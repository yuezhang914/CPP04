/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 08:01:32 by yzhang2           #+#    #+#             */
/*   Updated: 2026/05/10 15:42:06 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    const Animal *meta = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;
    cat->makeSound();
    dog->makeSound();
    meta->makeSound();

    delete meta;
    delete dog;
    delete cat;

    const WrongAnimal *wrong = new WrongCat();
    std::cout << wrong->getType() << std::endl;
    wrong->makeSound();
    delete wrong;

    return 0;
}



// static void printTitle(std::string const& title)
// {
//     std::cout << std::endl;
//     std::cout << "===== " << title << " =====" << std::endl;
// }

// static void testBasicAnimal()
// {
//     const Animal* meta;
//     const Animal* dog;
//     const Animal* cat;

//     printTitle("Basic Animal / Dog / Cat test");

//     meta = new Animal();
//     dog = new Dog();
//     cat = new Cat();

//     std::cout << "dog type: " << dog->getType() << std::endl;
//     std::cout << "cat type: " << cat->getType() << std::endl;
//     std::cout << "meta type: " << meta->getType() << std::endl;

//     std::cout << "cat sound: ";
//     cat->makeSound();

//     std::cout << "dog sound: ";
//     dog->makeSound();

//     std::cout << "meta sound: ";
//     meta->makeSound();

//     delete meta;
//     delete dog;
//     delete cat;
// }

// static void testDirectObjects()
// {
//     Dog dog;
//     Cat cat;

//     printTitle("Direct object test");

//     std::cout << "dog type: " << dog.getType() << std::endl;
//     std::cout << "cat type: " << cat.getType() << std::endl;

//     std::cout << "dog sound: ";
//     dog.makeSound();

//     std::cout << "cat sound: ";
//     cat.makeSound();
// }

// static void testAnimalPointerArray()
// {
//     Animal* animals[6];
//     int index;

//     printTitle("Animal pointer array polymorphism test");

//     index = 0;
//     while (index < 6)
//     {
//         if (index < 3)
//             animals[index] = new Dog();
//         else
//             animals[index] = new Cat();
//         index++;
//     }

//     index = 0;
//     while (index < 6)
//     {
//         std::cout << "animals[" << index << "] type: ";
//         std::cout << animals[index]->getType() << std::endl;

//         std::cout << "animals[" << index << "] sound: ";
//         animals[index]->makeSound();

//         index++;
//     }

//     index = 0;
//     while (index < 6)
//     {
//         delete animals[index];
//         index++;
//     }
// }

// static void testCopy()
// {
//     Dog firstDog;
//     Dog secondDog(firstDog);
//     Dog thirdDog;

//     Cat firstCat;
//     Cat secondCat(firstCat);
//     Cat thirdCat;

//     printTitle("Copy constructor and assignment test");

//     thirdDog = firstDog;
//     thirdCat = firstCat;

//     std::cout << "firstDog type: " << firstDog.getType() << std::endl;
//     std::cout << "secondDog type: " << secondDog.getType() << std::endl;
//     std::cout << "thirdDog type: " << thirdDog.getType() << std::endl;

//     std::cout << "firstCat type: " << firstCat.getType() << std::endl;
//     std::cout << "secondCat type: " << secondCat.getType() << std::endl;
//     std::cout << "thirdCat type: " << thirdCat.getType() << std::endl;

//     firstDog.makeSound();
//     secondDog.makeSound();
//     thirdDog.makeSound();

//     firstCat.makeSound();
//     secondCat.makeSound();
//     thirdCat.makeSound();
// }

// static void testWrongPolymorphism()
// {
//     const WrongAnimal* wrongMeta;
//     const WrongAnimal* wrongCat;

//     printTitle("Wrong polymorphism test");

//     wrongMeta = new WrongAnimal();
//     wrongCat = new WrongCat();

//     std::cout << "wrongMeta type: " << wrongMeta->getType() << std::endl;
//     std::cout << "wrongCat type through WrongAnimal pointer: ";
//     std::cout << wrongCat->getType() << std::endl;

//     std::cout << "wrongMeta sound: ";
//     wrongMeta->makeSound();

//     std::cout << "wrongCat sound through WrongAnimal pointer: ";
//     wrongCat->makeSound();

//     delete wrongMeta;
//     delete wrongCat;
// }

// static void testWrongCatDirect()
// {
//     WrongCat wrongCat;

//     printTitle("WrongCat direct object test");

//     std::cout << "wrongCat type: " << wrongCat.getType() << std::endl;

//     std::cout << "wrongCat direct sound: ";
//     wrongCat.makeSound();
// }

// int main()
// {
//     testBasicAnimal();
//     testDirectObjects();
//     testAnimalPointerArray();
//     testCopy();
//     testWrongPolymorphism();
//     testWrongCatDirect();
//     return 0;
// }
