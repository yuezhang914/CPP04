/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 08:06:30 by yzhang2           #+#    #+#             */
/*   Updated: 2026/05/10 15:57:51 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    const int animalCount = 10;
    Animal *animals[animalCount];
    int index = 0;

    while (index < animalCount / 2)
    {
        animals[index] = new Dog();
        index++;
    }
    while (index < animalCount)
    {
        animals[index] = new Cat();
        index++;
    }
    index = 0;
    while (index < animalCount)
    {
        std::cout << animals[index]->getType() << ": ";
        animals[index]->makeSound();
        index++;
    }
    index = 0;
    while (index < animalCount)
    {
        delete animals[index];
        index++;
    }

    Dog firstDog;
    firstDog.setIdea(0, "I want a bone");
    Dog secondDog(firstDog);
    firstDog.setIdea(0, "I want to sleep");
    std::cout << firstDog.getIdea(0) << std::endl;
    std::cout << secondDog.getIdea(0) << std::endl;

    return 0;
}


// static void printTitle(std::string const& title)
// {
//     std::cout << std::endl;
//     std::cout << "===== " << title << " =====" << std::endl;
// }

// static void testAbstractAnimal()
// {
//     printTitle("Abstract Animal compile-time test");

//     std::cout << "Animal should be abstract now." << std::endl;
//     std::cout << "The following lines should not compile if uncommented:" << std::endl;
//     std::cout << "Animal animal;" << std::endl;
//     std::cout << "Animal* animal = new Animal();" << std::endl;

//     /*
//     Animal animal;
//     Animal* animalPointer = new Animal();
//     delete animalPointer;
//     */
// }

// static void testDogAndCatStillWork()
// {
//     Animal* dog;
//     Animal* cat;

//     printTitle("Dog and Cat still work through Animal pointer");

//     dog = new Dog();
//     cat = new Cat();

//     std::cout << "dog type: " << dog->getType() << std::endl;
//     std::cout << "cat type: " << cat->getType() << std::endl;

//     std::cout << "dog sound: ";
//     dog->makeSound();

//     std::cout << "cat sound: ";
//     cat->makeSound();

//     delete dog;
//     delete cat;
// }

// static void testArrayStillWorks()
// {
//     Animal* animals[8];
//     int index;

//     printTitle("Animal pointer array still works with abstract Animal");

//     index = 0;
//     while (index < 8)
//     {
//         if (index < 4)
//             animals[index] = new Dog();
//         else
//             animals[index] = new Cat();
//         index++;
//     }

//     index = 0;
//     while (index < 8)
//     {
//         std::cout << "animals[" << index << "] type: ";
//         std::cout << animals[index]->getType() << std::endl;
//         animals[index]->makeSound();
//         index++;
//     }

//     index = 0;
//     while (index < 8)
//     {
//         delete animals[index];
//         index++;
//     }
// }

// static void testDogDeepCopy()
// {
//     Dog firstDog;
//     Dog secondDog;

//     printTitle("Dog deep copy still works in ex02");

//     firstDog.setIdea(0, "dog original idea");
//     secondDog = firstDog;

//     std::cout << "firstDog idea before change: ";
//     std::cout << firstDog.getIdea(0) << std::endl;

//     std::cout << "secondDog idea before change: ";
//     std::cout << secondDog.getIdea(0) << std::endl;

//     firstDog.setIdea(0, "dog changed idea");

//     std::cout << "firstDog idea after change: ";
//     std::cout << firstDog.getIdea(0) << std::endl;

//     std::cout << "secondDog idea after firstDog changed: ";
//     std::cout << secondDog.getIdea(0) << std::endl;
// }

// static void testCatDeepCopy()
// {
//     Cat firstCat;
//     Cat secondCat;

//     printTitle("Cat deep copy still works in ex02");

//     firstCat.setIdea(0, "cat original idea");
//     secondCat = firstCat;

//     std::cout << "firstCat idea before change: ";
//     std::cout << firstCat.getIdea(0) << std::endl;

//     std::cout << "secondCat idea before change: ";
//     std::cout << secondCat.getIdea(0) << std::endl;

//     firstCat.setIdea(0, "cat changed idea");

//     std::cout << "firstCat idea after change: ";
//     std::cout << firstCat.getIdea(0) << std::endl;

//     std::cout << "secondCat idea after firstCat changed: ";
//     std::cout << secondCat.getIdea(0) << std::endl;
// }

// static void testDirectConcreteObjects()
// {
//     Dog dog;
//     Cat cat;

//     printTitle("Direct Dog and Cat objects still work");

//     std::cout << "dog type: " << dog.getType() << std::endl;
//     std::cout << "cat type: " << cat.getType() << std::endl;

//     dog.makeSound();
//     cat.makeSound();
// }

// int main()
// {
//     testAbstractAnimal();
//     testDogAndCatStillWork();
//     testArrayStillWorks();
//     testDogDeepCopy();
//     testCatDeepCopy();
//     testDirectConcreteObjects();
//     return 0;
// }
