/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 08:08:57 by yzhang2           #+#    #+#             */
/*   Updated: 2026/04/26 08:09:01 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

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
