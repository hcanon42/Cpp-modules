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

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) : ClapTrap(100, 100, 120, 120, 1, name, 60, 20, 5, (std::string)"SUP3R-TR")
{
	srand(time(0));
	std::cout << "SUP3R-TR ENGAGED. PLEASE MOVE OUT OF THE WAY." << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &ref)
{
	*this = ref;
	srand(time(0));;
	std::cout << "DOUBLE SUP3R-TR FOR DOUBLE POWER. NOW 25% OFF FOR 2 BOUGHT." << std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << "SUP3R-TR DISENGAGED. MISSION ACCOMPLISHED." << std::endl;
}

SuperTrap	&SuperTrap::operator=(SuperTrap const &rhs)
{
	this->_armor = rhs._armor;
	this->_distDamage = rhs._distDamage;
	this->_Energy = rhs._Energy;
	this->_HP = rhs._HP;
	this->_level = rhs._level;
	this->_maxEnergy = rhs._maxEnergy;
	this->_maxHP = rhs._maxHP;
	this->_meleeDamage = rhs._meleeDamage;
	this->_name = rhs._name;
	this->_type = rhs._type;
	return (*this);
}
