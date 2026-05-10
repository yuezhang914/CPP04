# CPP Module 04

## Subtype Polymorphism, Abstract Classes, and Interfaces

This project is part of the 42 C++ modules. The goal of CPP04 is to understand how C++ handles polymorphism through inheritance, virtual functions, abstract classes, and interface-like pure abstract classes.

The project is divided into four exercises:

- `ex00`: Polymorphism
- `ex01`: Dynamic memory and deep copy
- `ex02`: Abstract classes
- `ex03`: Interfaces and recap

All exercises are written in C++98 and compiled with:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

---

# ex00: Polymorphism

## Main learning goal

The purpose of this exercise is to understand **runtime polymorphism**.

The key idea is that a base class pointer can point to a derived class object, and when a virtual function is called, C++ should execute the derived class version of that function.

For example:

```cpp
Animal* animal = new Dog();
animal->makeSound();
```

Even though the pointer type is `Animal*`, the real object is a `Dog`, so the program should call `Dog::makeSound()`.

## What was implemented

In this exercise, the following classes were implemented:

- `Animal`
- `Dog`
- `Cat`
- `WrongAnimal`
- `WrongCat`

`Animal` is the base class. It contains a protected `type` attribute and provides a virtual `makeSound()` function.

`Dog` and `Cat` inherit from `Animal`. Each class sets its own type and overrides `makeSound()` with its own sound.

`WrongAnimal` and `WrongCat` were implemented as a counterexample. Their purpose is to show what happens when `makeSound()` is not virtual. When a `WrongAnimal*` points to a `WrongCat`, the base class function is called instead of the derived class function.

## What was learned

This exercise shows why `virtual` is necessary for polymorphism.

Without `virtual`, C++ decides which function to call based on the pointer type. With `virtual`, C++ decides which function to call based on the real object type at runtime.

This exercise also shows why base classes that are meant to be used polymorphically should have a virtual destructor.

---

# ex01: I don’t want to set the world on fire

## Main learning goal

The purpose of this exercise is to understand **dynamic memory management** and **deep copy** in polymorphic classes.

In ex00, `Dog` and `Cat` only had simple data. In this exercise, both classes own a dynamically allocated `Brain` object. This makes copying and destruction more important.

## What was implemented

A new class was added:

- `Brain`

`Brain` contains an array of 100 `std::string` ideas.

`Dog` and `Cat` now each have a private `Brain*` attribute. Their constructors allocate a new `Brain`, and their destructors delete it.

The program also creates an array of `Animal*` containing both `Dog` and `Cat` objects. At the end of the program, all animals are deleted through `Animal*` pointers.

Deep copy logic was implemented for `Dog` and `Cat`, so copied animals do not share the same `Brain`.

## What was learned

This exercise shows why a virtual destructor is important.

When deleting a `Dog` or `Cat` through an `Animal*`, the correct derived class destructor must be called. Otherwise, the `Brain` object may not be deleted, causing a memory leak.

This exercise also explains the difference between shallow copy and deep copy.

A shallow copy would copy only the `Brain*` address, causing two animals to share the same brain. A deep copy creates a new `Brain` object and copies the content into it, so each animal owns its own independent brain.

This exercise also helps avoid object slicing by using an array of `Animal*` instead of an array of `Animal` objects.

---

# ex02: Abstract class

## Main learning goal

The purpose of this exercise is to understand **abstract classes** and **pure virtual functions**.

In the previous exercises, it was possible to create an `Animal` object directly. However, a generic animal does not really have a specific sound. Only concrete animals such as `Dog` and `Cat` should be created.

## What was implemented

The `Animal` class was changed so that it can no longer be instantiated directly.

This was done by making `makeSound()` a pure virtual function:

```cpp
virtual void makeSound() const = 0;
```

`Dog` and `Cat` still inherit from `Animal` and still implement their own `makeSound()` functions.

The rest of the behavior from ex01 remains valid:

- `Dog` and `Cat` still own a `Brain`
- deep copy still works
- deletion through `Animal*` still works
- polymorphism still works

## What was learned

This exercise shows that an abstract class can be used as a common interface or parent type, even though it cannot be directly instantiated.

It is still possible to write:

```cpp
Animal* animal = new Dog();
```

But it is no longer possible to write:

```cpp
Animal animal;
Animal* animal = new Animal();
```

This makes the design safer because it prevents meaningless base class objects from being created.

---

# ex03: Interface & recap

## Main learning goal

The purpose of this exercise is to understand how C++ can simulate **interfaces** using pure abstract classes.

C++98 does not have an `interface` keyword. Instead, an interface is usually written as a class containing pure virtual functions.

This exercise also combines the main ideas from the previous exercises:

- polymorphism
- abstract classes
- virtual destructors
- deep copy
- dynamic memory ownership
- cloning derived objects through a base pointer

## What was implemented

The following classes and interfaces were implemented:

- `AMateria`
- `Ice`
- `Cure`
- `ICharacter`
- `Character`
- `IMateriaSource`
- `MateriaSource`

`AMateria` is an abstract base class for materia objects. It stores a type and declares a pure virtual `clone()` function.

`Ice` and `Cure` are concrete materia classes. Each class implements `clone()` and `use()`.

`ICharacter` is an interface that defines what a character must be able to do:

- get its name
- equip materia
- unequip materia
- use materia

`Character` implements `ICharacter`. It owns an inventory of 4 `AMateria*` slots. It can equip materia, unequip materia, and use materia on another character.

`IMateriaSource` is an interface for a materia source. It defines functions to learn materia and create materia by type.

`MateriaSource` implements `IMateriaSource`. It can learn up to 4 materia templates and create new materia objects by cloning the learned templates.

## What was learned

This exercise shows how interfaces work in C++ through pure abstract classes.

It also shows why `clone()` is useful. When working with an `AMateria*`, the program may not know whether the real object is an `Ice` or a `Cure`. Calling `clone()` allows the real derived object to create a correct copy of itself.

This exercise also emphasizes memory ownership. `Character` must correctly delete the materia it owns. `MateriaSource` must correctly delete the materia templates it stores. `unequip()` must not delete materia, so the caller must handle the unequipped pointer to avoid memory leaks.

---

# Final summary

CPP Module 04 teaches how to design class hierarchies that behave correctly through base class pointers.

The most important concepts learned in this module are:

- how virtual functions enable runtime polymorphism
- why base classes should have virtual destructors
- how dynamic memory requires clear ownership
- why deep copy is necessary when a class owns pointer members
- why object slicing should be avoided
- how pure virtual functions create abstract classes
- how C++ uses pure abstract classes to simulate interfaces
- how `clone()` helps copy derived objects through base class pointers

Overall, this module is about moving from simple class writing to real object-oriented design.
