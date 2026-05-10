/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 08:09:06 by yzhang2           #+#    #+#             */
/*   Updated: 2026/05/10 15:59:08 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    int index = 0;

    while (index < 4)
    {
        this->memory[index] = 0;
        index++;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    int index = 0;

    while (index < 4)
    {
        this->memory[index] = 0;
        index++;
    }
    this->copyMemory(other);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        this->clearMemory();
        this->copyMemory(other);
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    this->clearMemory();
}

void MateriaSource::learnMateria(AMateria *materia)
{
    int index = 0;

    if (materia == 0)
        return;
    while (index < 4)
    {
        if (this->memory[index] == 0)
        {
            this->memory[index] = materia;
            return;
        }
        index++;
    }
    delete materia;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
    int index = 0;

    while (index < 4)
    {
        if (this->memory[index] != 0 && this->memory[index]->getType() == type)
            return this->memory[index]->clone();
        index++;
    }
    return 0;
}

void MateriaSource::clearMemory()
{
    int index = 0;

    while (index < 4)
    {
        delete this->memory[index];
        this->memory[index] = 0;
        index++;
    }
}

void MateriaSource::copyMemory(const MateriaSource &other)
{
    int index = 0;

    while (index < 4)
    {
        if (other.memory[index] != 0)
            this->memory[index] = other.memory[index]->clone();
        else
            this->memory[index] = 0;
        index++;
    }
}
