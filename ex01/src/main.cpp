/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 08:04:37 by yzhang2           #+#    #+#             */
/*   Updated: 2026/05/10 15:44:29 by yzhang2          ###   ########.fr       */
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

    Cat firstCat;
    firstCat.setIdea(0, "I want fish");
    Cat secondCat;
    secondCat = firstCat;
    firstCat.setIdea(0, "I want a box");
    std::cout << firstCat.getIdea(0) << std::endl;
    std::cout << secondCat.getIdea(0) << std::endl;

    return 0;
}



// static void printTitle(std::string const& title)
// {
//     std::cout << std::endl;
//     std::cout << "===== " << title << " =====" << std::endl;
// }

// static void testBasicDelete()
// {
//     const Animal* dog;
//     const Animal* cat;

//     printTitle("Basic delete through Animal pointer test");

//     dog = new Dog();
//     cat = new Cat();

//     std::cout << "dog type: " << dog->getType() << std::endl;
//     std::cout << "cat type: " << cat->getType() << std::endl;

//     dog->makeSound();
//     cat->makeSound();

//     delete dog;
//     delete cat;
// }

// static void testAnimalArray()
// {
//     Animal* animals[10];
//     int index;

//     printTitle("Animal pointer array with Dog and Cat test");

//     index = 0;
//     while (index < 10)
//     {
//         if (index < 5)
//             animals[index] = new Dog();
//         else
//             animals[index] = new Cat();
//         index++;
//     }

//     index = 0;
//     while (index < 10)
//     {
//         std::cout << "animals[" << index << "] type: ";
//         std::cout << animals[index]->getType() << std::endl;

//         std::cout << "animals[" << index << "] sound: ";
//         animals[index]->makeSound();

//         index++;
//     }

//     index = 0;
//     while (index < 10)
//     {
//         delete animals[index];
//         index++;
//     }
// }

// static void testDogDeepCopyConstructor()
// {
//     Dog firstDog;
//     Dog secondDog(firstDog);

//     printTitle("Dog deep copy constructor test");

//     firstDog.setIdea(0, "first dog wants to run");
//     firstDog.setIdea(1, "first dog wants to eat");

//     secondDog = firstDog;

//     std::cout << "After assignment:" << std::endl;
//     std::cout << "firstDog idea 0: " << firstDog.getIdea(0) << std::endl;
//     std::cout << "secondDog idea 0: " << secondDog.getIdea(0) << std::endl;

//     firstDog.setIdea(0, "first dog changed its idea");

//     std::cout << "After changing firstDog:" << std::endl;
//     std::cout << "firstDog idea 0: " << firstDog.getIdea(0) << std::endl;
//     std::cout << "secondDog idea 0: " << secondDog.getIdea(0) << std::endl;
// }

// static void testCatDeepCopyConstructor()
// {
//     Cat firstCat;
//     Cat secondCat(firstCat);

//     printTitle("Cat deep copy constructor test");

//     firstCat.setIdea(0, "first cat wants to sleep");
//     firstCat.setIdea(1, "first cat wants fish");

//     secondCat = firstCat;

//     std::cout << "After assignment:" << std::endl;
//     std::cout << "firstCat idea 0: " << firstCat.getIdea(0) << std::endl;
//     std::cout << "secondCat idea 0: " << secondCat.getIdea(0) << std::endl;

//     firstCat.setIdea(0, "first cat changed its idea");

//     std::cout << "After changing firstCat:" << std::endl;
//     std::cout << "firstCat idea 0: " << firstCat.getIdea(0) << std::endl;
//     std::cout << "secondCat idea 0: " << secondCat.getIdea(0) << std::endl;
// }

// static void testCopyConstructorOnly()
// {
//     Dog originalDog;
//     Dog copiedDog(originalDog);

//     Cat originalCat;
//     Cat copiedCat(originalCat);

//     printTitle("Copy constructor only test");

//     originalDog.setIdea(0, "original dog idea");
//     originalCat.setIdea(0, "original cat idea");

//     Dog anotherDog(originalDog);
//     Cat anotherCat(originalCat);

//     std::cout << "originalDog idea: " << originalDog.getIdea(0) << std::endl;
//     std::cout << "anotherDog idea: " << anotherDog.getIdea(0) << std::endl;

//     std::cout << "originalCat idea: " << originalCat.getIdea(0) << std::endl;
//     std::cout << "anotherCat idea: " << anotherCat.getIdea(0) << std::endl;

//     originalDog.setIdea(0, "original dog changed");
//     originalCat.setIdea(0, "original cat changed");

//     std::cout << "After changing originals:" << std::endl;
//     std::cout << "originalDog idea: " << originalDog.getIdea(0) << std::endl;
//     std::cout << "anotherDog idea: " << anotherDog.getIdea(0) << std::endl;

//     std::cout << "originalCat idea: " << originalCat.getIdea(0) << std::endl;
//     std::cout << "anotherCat idea: " << anotherCat.getIdea(0) << std::endl;
// }

// static void testIdeaIndexLimits()
// {
//     Dog dog;
//     Cat cat;

//     printTitle("Idea index limit test");

//     dog.setIdea(0, "dog first idea");
//     dog.setIdea(99, "dog last idea");
//     dog.setIdea(-1, "bad dog idea");
//     dog.setIdea(100, "bad dog idea");

//     cat.setIdea(0, "cat first idea");
//     cat.setIdea(99, "cat last idea");
//     cat.setIdea(-1, "bad cat idea");
//     cat.setIdea(100, "bad cat idea");

//     std::cout << "dog idea 0: " << dog.getIdea(0) << std::endl;
//     std::cout << "dog idea 99: " << dog.getIdea(99) << std::endl;
//     std::cout << "dog idea -1: " << dog.getIdea(-1) << std::endl;
//     std::cout << "dog idea 100: " << dog.getIdea(100) << std::endl;

//     std::cout << "cat idea 0: " << cat.getIdea(0) << std::endl;
//     std::cout << "cat idea 99: " << cat.getIdea(99) << std::endl;
//     std::cout << "cat idea -1: " << cat.getIdea(-1) << std::endl;
//     std::cout << "cat idea 100: " << cat.getIdea(100) << std::endl;
// }

// int main()
// {
//     testBasicDelete();
//     testAnimalArray();
//     testDogDeepCopyConstructor();
//     testCatDeepCopyConstructor();
//     testCopyConstructorOnly();
//     testIdeaIndexLimits();
//     return 0;
// }
