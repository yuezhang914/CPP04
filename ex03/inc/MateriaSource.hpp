/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 08:07:52 by yzhang2           #+#    #+#             */
/*   Updated: 2026/05/10 15:58:33 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *memory[4];

    void clearMemory();
    void copyMemory(const MateriaSource &other);

public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    MateriaSource &operator=(const MateriaSource &other);
    virtual ~MateriaSource();

    virtual void learnMateria(AMateria *materia);
    virtual AMateria *createMateria(const std::string &type);
};

#endif
