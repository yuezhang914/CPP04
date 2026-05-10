/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 08:08:57 by yzhang2           #+#    #+#             */
/*   Updated: 2026/05/10 15:59:04 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>


int main()
{
    IMateriaSource *source = new MateriaSource();
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());

    ICharacter *me = new Character("me");
    AMateria *materia;

    materia = source->createMateria("ice");
    me->equip(materia);
    materia = source->createMateria("cure");
    me->equip(materia);

    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);

    Character first("first");
    first.equip(source->createMateria("ice"));
    Character second(first);
    first.use(0, *bob);
    second.use(0, *bob);

    delete bob;
    delete me;
    delete source;
    return 0;
}


// static void printTitle(std::string const& title)
// {
//     std::cout << std::endl;
//     std::cout << "===== " << title << " =====" << std::endl;
// }

// static void testSubjectMain()
// {
//     IMateriaSource* source;
//     ICharacter* me;
//     ICharacter* bob;
//     AMateria* temporary;

//     printTitle("Subject main test");

//     source = new MateriaSource();

//     source->learnMateria(new Ice());
//     source->learnMateria(new Cure());

//     me = new Character("me");

//     temporary = source->createMateria("ice");
//     me->equip(temporary);

//     temporary = source->createMateria("cure");
//     me->equip(temporary);

//     bob = new Character("bob");

//     me->use(0, *bob);
//     me->use(1, *bob);

//     delete bob;
//     delete me;
//     delete source;
// }

// static void testUnknownMateria()
// {
//     IMateriaSource* source;
//     AMateria* materia;

//     printTitle("Unknown materia type test");

//     source = new MateriaSource();

//     source->learnMateria(new Ice());

//     materia = source->createMateria("fire");
//     if (materia == 0)
//         std::cout << "createMateria(\"fire\") returned 0" << std::endl;
//     else
//         std::cout << "unexpected materia created" << std::endl;

//     delete materia;
//     delete source;
// }

// static void testFullMateriaSource()
// {
//     IMateriaSource* source;
//     AMateria* materia;

//     printTitle("Full MateriaSource test");

//     source = new MateriaSource();

//     source->learnMateria(new Ice());
//     source->learnMateria(new Cure());
//     source->learnMateria(new Ice());
//     source->learnMateria(new Cure());
//     source->learnMateria(new Ice());

//     materia = source->createMateria("ice");
//     if (materia != 0)
//     {
//         std::cout << "ice created from learned memory" << std::endl;
//         delete materia;
//     }

//     materia = source->createMateria("cure");
//     if (materia != 0)
//     {
//         std::cout << "cure created from learned memory" << std::endl;
//         delete materia;
//     }

//     delete source;
// }

// static void testCharacterInventoryFull()
// {
//     IMateriaSource* source;
//     ICharacter* me;
//     ICharacter* bob;
//     AMateria* materia;

//     printTitle("Character full inventory test");

//     source = new MateriaSource();
//     source->learnMateria(new Ice());
//     source->learnMateria(new Cure());

//     me = new Character("me");
//     bob = new Character("bob");

//     materia = source->createMateria("ice");
//     me->equip(materia);

//     materia = source->createMateria("cure");
//     me->equip(materia);

//     materia = source->createMateria("ice");
//     me->equip(materia);

//     materia = source->createMateria("cure");
//     me->equip(materia);

//     materia = source->createMateria("ice");
//     me->equip(materia);

//     me->use(0, *bob);
//     me->use(1, *bob);
//     me->use(2, *bob);
//     me->use(3, *bob);
//     me->use(4, *bob);

//     delete bob;
//     delete me;
//     delete source;
// }

// static void testUseBadIndex()
// {
//     IMateriaSource* source;
//     ICharacter* me;
//     ICharacter* bob;
//     AMateria* materia;

//     printTitle("Bad index use test");

//     source = new MateriaSource();
//     source->learnMateria(new Ice());

//     me = new Character("me");
//     bob = new Character("bob");

//     materia = source->createMateria("ice");
//     me->equip(materia);

//     std::cout << "use index -1:" << std::endl;
//     me->use(-1, *bob);

//     std::cout << "use index 0:" << std::endl;
//     me->use(0, *bob);

//     std::cout << "use index 4:" << std::endl;
//     me->use(4, *bob);

//     std::cout << "use index 100:" << std::endl;
//     me->use(100, *bob);

//     delete bob;
//     delete me;
//     delete source;
// }

// static void testUnequip()
// {
//     IMateriaSource* source;
//     Character* me;
//     Character* bob;
//     AMateria* firstMateria;
//     AMateria* secondMateria;

//     printTitle("Unequip test");

//     source = new MateriaSource();
//     source->learnMateria(new Ice());
//     source->learnMateria(new Cure());

//     me = new Character("me");
//     bob = new Character("bob");

//     firstMateria = source->createMateria("ice");
//     secondMateria = source->createMateria("cure");

//     me->equip(firstMateria);
//     me->equip(secondMateria);

//     std::cout << "Before unequip:" << std::endl;
//     me->use(0, *bob);
//     me->use(1, *bob);

//     me->unequip(0);

//     std::cout << "After unequip slot 0:" << std::endl;
//     me->use(0, *bob);
//     me->use(1, *bob);

//     delete firstMateria;

//     me->unequip(-1);
//     me->unequip(4);
//     me->unequip(100);

//     delete bob;
//     delete me;
//     delete source;
// }

// static void testCharacterCopyConstructor()
// {
//     IMateriaSource* source;
//     Character original("original");
//     Character target("target");
//     AMateria* firstMateria;
//     AMateria* secondMateria;

//     printTitle("Character copy constructor test");

//     source = new MateriaSource();
//     source->learnMateria(new Ice());
//     source->learnMateria(new Cure());

//     firstMateria = source->createMateria("ice");
//     original.equip(firstMateria);

//     secondMateria = source->createMateria("cure");
//     original.equip(secondMateria);

//     Character copied(original);

//     std::cout << "original uses:" << std::endl;
//     original.use(0, target);
//     original.use(1, target);

//     std::cout << "copied uses:" << std::endl;
//     copied.use(0, target);
//     copied.use(1, target);

//     original.unequip(0);
//     delete firstMateria;

//     std::cout << "After original unequip slot 0:" << std::endl;
//     std::cout << "original uses slot 0:" << std::endl;
//     original.use(0, target);

//     std::cout << "copied uses slot 0:" << std::endl;
//     copied.use(0, target);

//     delete source;
// }

// static void testCharacterAssignment()
// {
//     IMateriaSource* source;
//     Character first("first");
//     Character second("second");
//     Character target("target");
//     AMateria* firstMateria;
//     AMateria* secondMateria;

//     printTitle("Character assignment operator test");

//     source = new MateriaSource();
//     source->learnMateria(new Ice());
//     source->learnMateria(new Cure());

//     firstMateria = source->createMateria("ice");
//     first.equip(firstMateria);

//     secondMateria = source->createMateria("cure");
//     second.equip(secondMateria);

//     std::cout << "Before assignment:" << std::endl;
//     std::cout << "first uses slot 0:" << std::endl;
//     first.use(0, target);

//     std::cout << "second uses slot 0:" << std::endl;
//     second.use(0, target);

//     second = first;

//     std::cout << "After second = first:" << std::endl;
//     std::cout << "first uses slot 0:" << std::endl;
//     first.use(0, target);

//     std::cout << "second uses slot 0:" << std::endl;
//     second.use(0, target);

//     first.unequip(0);
//     delete firstMateria;

//     std::cout << "After first unequip slot 0:" << std::endl;
//     std::cout << "first uses slot 0:" << std::endl;
//     first.use(0, target);

//     std::cout << "second uses slot 0:" << std::endl;
//     second.use(0, target);

//     delete source;
// }

// static void testMateriaClone()
// {
//     AMateria* ice;
//     AMateria* cure;
//     AMateria* iceCopy;
//     AMateria* cureCopy;
//     Character target("target");

//     printTitle("Materia clone test");

//     ice = new Ice();
//     cure = new Cure();

//     iceCopy = ice->clone();
//     cureCopy = cure->clone();

//     std::cout << "ice type: " << ice->getType() << std::endl;
//     std::cout << "iceCopy type: " << iceCopy->getType() << std::endl;
//     std::cout << "cure type: " << cure->getType() << std::endl;
//     std::cout << "cureCopy type: " << cureCopy->getType() << std::endl;

//     iceCopy->use(target);
//     cureCopy->use(target);

//     delete ice;
//     delete cure;
//     delete iceCopy;
//     delete cureCopy;
// }

// static void testNullEquipAndEmptyUse()
// {
//     Character me("me");
//     Character bob("bob");

//     printTitle("Null equip and empty use test");

//     me.equip(0);

//     std::cout << "use empty slot 0:" << std::endl;
//     me.use(0, bob);

//     std::cout << "use empty slot 3:" << std::endl;
//     me.use(3, bob);
// }

// int main()
// {
//     testSubjectMain();
//     testUnknownMateria();
//     testFullMateriaSource();
//     testCharacterInventoryFull();
//     testUseBadIndex();
//     testUnequip();
//     testCharacterCopyConstructor();
//     testCharacterAssignment();
//     testMateriaClone();
//     testNullEquipAndEmptyUse();
//     return 0;
// }
