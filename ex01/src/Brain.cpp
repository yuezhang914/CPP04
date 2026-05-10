/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 08:04:09 by yzhang2           #+#    #+#             */
/*   Updated: 2026/05/10 15:56:40 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.hpp"

Brain::Brain()
{
    int index = 0;

    std::cout << "Brain constructor called" << std::endl;
    while (index < 100)
    {
        this->ideas[index] = "";
        index++;
    }
}

Brain::Brain(const Brain &other)
{
    int index = 0;

    std::cout << "Brain copy constructor called" << std::endl;
    while (index < 100)
    {
        this->ideas[index] = other.ideas[index];
        index++;
    }
}

Brain &Brain::operator=(const Brain &other)
{
    int index = 0;

    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other)
    {
        while (index < 100)
        {
            this->ideas[index] = other.ideas[index];
            index++;
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string &idea)
{
    if (index < 0 || index >= 100)
        return;
    this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if (index < 0 || index >= 100)
        return "";
    return this->ideas[index];
}
