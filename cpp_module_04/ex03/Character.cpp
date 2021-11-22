/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcanon <hcanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:00:46 by hcanon            #+#    #+#             */
/*   Updated: 2020/11/12 12:12:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
	int		i;

	i = -1;
	while (++i < 4)
		_inventory[i] = NULL;
}

Character::Character(Character const &ref)
{
	int		i;

	i = -1;
	while (++i < 4)
		this->_inventory[i] = NULL;
	this->_name = std::string(ref.getName());
	i = -1;
	while (++i < 4)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (!ref.getMateria(i))
			this->_inventory[i] = NULL;
		else
			this->_inventory[i] = ref.getMateria(i)->clone();
	}
}

Character::~Character()
{
	int		i;

	i = -1;
	while (++i < 4)
		if (this->_inventory[i])
			delete this->_inventory[i];
}

Character				&Character::operator=(Character const &rhs)
{
	int		i;

	i = -1;
	this->_name = rhs.getName();
	while (++i < 4)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (!rhs.getMateria(i))
			this->_inventory[i] = NULL;
		else
			this->_inventory[i] = rhs.getMateria(i)->clone();
	}
	return (*this);
}

std::string const		&Character::getName() const
{
	return (this->_name);
}

void					Character::equip(AMateria *m)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			break ;
		}
	}
}

void					Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	this->_inventory[idx] = NULL;
}

void					Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || !this->_inventory[idx])
		return ;
	this->_inventory[idx]->use(target);
}

AMateria				*Character::getMateria(int idx) const
{
	if (idx < 0 || idx > 3)
		return (NULL);
	return this->_inventory[idx];
}
