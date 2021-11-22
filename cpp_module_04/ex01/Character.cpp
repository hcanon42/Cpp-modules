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
#include <iostream>

Character::Character(std::string name) : _name(name), _apPoints(40), _weapon(NULL)
{
}

Character::Character(Character const &ref)
{
	*this = ref;
}

Character::~Character()
{
}

Character&		Character::operator=(Character const &rhs)
{
	this->_name = rhs.getName();
	this->_apPoints = rhs.getAPPoints();
	this->_weapon = rhs.getWeapon();
	return (*this);
}

void			Character::recoverAP()
{
	if (this->getAPPoints() > 30)
		this->_apPoints = 40;
	else
		this->_apPoints += 10;
}

void			Character::equip(AWeapon* weapon)
{
	this->_weapon = weapon;
}

void			Character::attack(Enemy* enemy)
{
	if (enemy == NULL || this->_weapon == NULL || this->_apPoints < this->_weapon->getAPCost())
		return;
	std::cout << this->_name << " attaque " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
	this->_weapon->attack();
	enemy->takeDamage(this->_weapon->getDamage());
	this->_apPoints -= this->_weapon->getAPCost();
	if (enemy->getHP() <= 0)
		delete enemy;
}

std::string		Character::getName() const
{
	return (this->_name);
}

int				Character::getAPPoints() const
{
	return (this->_apPoints);
}

AWeapon			*Character::getWeapon() const
{
	return (this->_weapon);
}

std::ostream	&operator<<(std::ostream &os, Character const &c)
{
	if (c.getWeapon())
		os << c.getName() << " has " << c.getAPPoints() << " AP and carries a " << c.getWeapon()->getName() << std::endl;
	else
		os << c.getName() << " has " << c.getAPPoints() << " AP and is unarmed" << std::endl;
	return (os);
}
