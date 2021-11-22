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

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(100, 100, 100, 100, 1, name, 30, 20, 5, (std::string)"FR4G-TR")
{
	srand(time(0));
	std::cout << "IT IS ALIIIIVE ! Wait, am I ?" << std::endl;
}

FragTrap::FragTrap(FragTrap const &ref)
{
	*this = ref;
	this->_type = "FR4G-TR";
	std::cout << "CtrlC CtrlV achieved !" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Minion ! Protect me while I run away cowardly !" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
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
	return (*this);
}

void		FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	int		i;

	if (this->_Energy < 25)
	{
		std::cout << "Nope I'm a bit tired right now. You'd rather ask one of my minions." << std::endl;
		return ;
	}
	this->_Energy -= 25;
	i = rand() % 5;
	if (i == 0)
		std::cout << "FR4G-TR " << this->_name << " dances so bad it damages " << target << " !" << std::endl;
	else if (i == 1)
		std::cout << "FR4G-TR " << this->_name << " shrieks in fear, making " << target << "'s ears bleed !" << std::endl;
	else if (i == 2)
		std::cout << "FR4G-TR " << this->_name << " is so annoying towards you that " << target << " develops pity and decides to make peace !" << std::endl;
	else if (i == 3)
		std::cout << "FR4G-TR " << this->_name << " trips over a little rock, being the cause of a terrible avalanche causing dozens of deaths, including " << target << " !" << std::endl;
	else
		std::cout << "FR4G-TR " << this->_name << " threatens the enemies, but it is so ridiculous that " << target << " laughs himself to death !" << std::endl;
}
