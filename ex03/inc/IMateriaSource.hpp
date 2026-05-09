/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 08:08:07 by yzhang2           #+#    #+#             */
/*   Updated: 2026/04/26 08:08:12 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIA_SOURCE_HPP
#define IMATERIA_SOURCE_HPP

#include <string>

class AMateria;

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}

    virtual void learnMateria(AMateria *materia) = 0;
    virtual AMateria *createMateria(const std::string &type) = 0;
};

#endif
