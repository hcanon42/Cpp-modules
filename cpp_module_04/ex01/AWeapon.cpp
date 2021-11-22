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

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string name, int apcost, int damage) : _name(name), _apcost(apcost < 0 ? 0 : apcost), _damage(damage < 0 ? 0 : damage)
{
}

AWeapon::AWeapon(AWeapon const &ref)
{
	*this = ref;
}

AWeapon::~AWeapon()
{
}

AWeapon& 		AWeapon::operator=(AWeapon const &other)
{
	this->_name = other.getName();
	this->_apcost = other.getAPCost();
	this->_damage = other.getDamage();
	return (*this);
}

std::string 	AWeapon::getName() const
{
	return (this->_name);
}

int 			AWeapon::getAPCost() const
{
	return (this->_apcost);
}

int 			AWeapon::getDamage() const
{
	return (this->_damage);
}
