/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 08:06:30 by yzhang2           #+#    #+#             */
/*   Updated: 2026/04/26 08:06:34 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

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
