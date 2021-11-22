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

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(100, 100, 50, 50, 1, name, 20, 15, 3, (std::string)"SC4V-TR")
{
	srand(time(0));
	std::cout << "Sorry I'm late..." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &ref)
{
	*this = ref;
	std::cout << "A useless robot just got copied" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "I'm sorry I should better get going..." << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
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

void		ScavTrap::challengeNewcomer()
{
	int		i;

	if (this->_Energy < 25)
	{
		std::cout << "I'm sooorry I have no energy left. Don't hurt me please !" << std::endl;
		return ;
	}
	this->_Energy -= 25;
	i = rand() % 5;
	if (i == 0)
		std::cout << "SC4V-TR " << this->_name << " challenges you to steal the diamond pony of handsome Jack !" << std::endl;
	else if (i == 1)
		std::cout << "SC4V-TR " << this->_name << " challenges you to make Claptrap shut the f**k up for once !" << std::endl;
	else if (i == 2)
		std::cout << "SC4V-TR " << this->_name << " challenges you to adpot a baby otter just to kill it before the SPA agent !" << std::endl;
	else if (i == 3)
		std::cout << "SC4V-TR " << this->_name << " challenges you to watch all episodes of Rick & Morty without laughing ! (This one is impossible)" << std::endl;
	else
		std::cout << "SC4V-TR " << this->_name << " challenges you to stay confined home ! LOOOL" << std::endl;
}
