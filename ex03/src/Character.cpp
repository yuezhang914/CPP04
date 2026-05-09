/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 08:08:29 by yzhang2           #+#    #+#             */
/*   Updated: 2026/04/26 08:08:33 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("unknown")
{
    int index = 0;

    while (index < 4)
    {
        this->inventory[index] = 0;
        index++;
    }
}

Character::Character(const std::string &name) : name(name)
{
    int index = 0;

    while (index < 4)
    {
        this->inventory[index] = 0;
        index++;
    }
}

Character::Character(const Character &other) : name(other.name)
{
    int index = 0;

    while (index < 4)
    {
        this->inventory[index] = 0;
        index++;
    }
    this->copyInventory(other);
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        this->clearInventory();
        this->name = other.name;
        this->copyInventory(other);
    }
    return *this;
}

Character::~Character()
{
    this->clearInventory();
}

const std::string &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *materia)
{
    int index = 0;

    if (materia == 0)
        return;
    while (index < 4)
    {
        if (this->inventory[index] == 0)
        {
            this->inventory[index] = materia;
            return;
        }
        index++;
    }
    delete materia;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4)
        return;
    if (this->inventory[idx] == 0)
        return;
    this->inventory[idx]->use(target);
}

void Character::clearInventory()
{
    int index = 0;

    while (index < 4)
    {
        delete this->inventory[index];
        this->inventory[index] = 0;
        index++;
    }
}

void Character::copyInventory(const Character &other)
{
    int index = 0;

    while (index < 4)
    {
        if (other.inventory[index] != 0)
            this->inventory[index] = other.inventory[index]->clone();
        else
            this->inventory[index] = 0;
        index++;
    }
}
