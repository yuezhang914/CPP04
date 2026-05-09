/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 08:07:11 by yzhang2           #+#    #+#             */
/*   Updated: 2026/04/26 08:07:16 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string name;
    AMateria *inventory[4];

    void clearInventory();
    void copyInventory(const Character &other);

public:
    Character();
    Character(const std::string &name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    virtual ~Character();

    virtual const std::string &getName() const;
    virtual void equip(AMateria *materia);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter &target);
};

#endif
