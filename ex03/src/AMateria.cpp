/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 08:08:20 by yzhang2           #+#    #+#             */
/*   Updated: 2026/05/10 15:58:38 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("")
{
}

AMateria::AMateria(const std::string &type) : type(type)
{
}

AMateria::AMateria(const AMateria &other) : type(other.type)
{
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

AMateria::~AMateria()
{
}

const std::string &AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}
