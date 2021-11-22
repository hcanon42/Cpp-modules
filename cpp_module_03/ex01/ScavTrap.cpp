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

ScavTrap::ScavTrap(std::string name) : _maxHP(100), _HP(100), _maxEnergy(50),  _Energy(50),  _level(1), _name(name), _meleeDamage(20),  _distDamage(15), _armor(3)
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
	return (*this);
}

void		ScavTrap::rangedAttack(std::string const &target) const
{
	std::cout << "SC4V-TR " << this->_name << " attacks " << target << " by launching pebbles and hiding, dealing " << this->_distDamage << " damage !" << std::endl;
}

void		ScavTrap::meleeAttack(std::string const &target) const
{
	std::cout << "SC4V-TR " << this->_name << " attacks shyly " << target << " dealing " << this->_meleeDamage << " damage !" << std::endl;
}

void		ScavTrap::takeDamage(unsigned int amount)
{
	int		i;

	if (this->_HP == 0)
	{
		std::cout << "Please stop hurting me I'm useless already..." << std::endl;
		return ;
	}
	if ((int)amount <= this->_armor)
		amount = 0;
	else
		amount -= this->_armor;
	i = amount;
	if ((int)amount > this->_HP)
		i = this->_HP;
	this->_HP -= amount;
	if (this->_HP < 0)
		this->_HP = 0;
	std::cout << "Argh... It must be deserved, I guess...\nSC4V-TR " << this->_name << " just go hit for " << i;
	if (this->_HP == 0)
		std::cout << " and died during the process by the way";
	std::cout << std::endl;
}

void		ScavTrap::beRepaired(unsigned int amount)
{
	int		i;

	i = amount;
	if (this->_HP + amount > 100)
		i = this->_maxHP - this->_HP;
	this->_HP += amount;
	if (this->_HP > this->_maxHP)
		this->_HP = this->_maxHP;
	std::cout << "Aw thank you ! I can offer you to hold the door if you want !\nSC4V-TR " << this->_name << " just healed for " << i << std::endl;
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

int			ScavTrap::getHP() const
{
	return (this->_HP);
}

int			ScavTrap::getEnergy() const
{
	return (this->_Energy);
}
