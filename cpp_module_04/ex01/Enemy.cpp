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

#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string type) : _hp((hp < 0 ? 0 : hp)), _type(type)
{
}

Enemy::Enemy(Enemy const &ref)
{
	*this = ref;
}

Enemy::~Enemy()
{
}

Enemy& 		Enemy::operator=(Enemy const &rhs)
{
	this->_hp = rhs.getHP();
	this->_type = rhs.getType();
	return (*this);
}

std::string Enemy::getType() const 
{ 
	return (this->_type);
}

int			Enemy::getHP() const
{
	return (this->_hp);
}

void		Enemy::setHP(int hp)
{
	this->_hp = hp;
}

void 		Enemy::takeDamage(int amount)
{
	if (amount < 0)
		return;
	if (amount > this->getHP())
		amount = this->getHP();
	this->setHP(this->getHP() - amount);
}
