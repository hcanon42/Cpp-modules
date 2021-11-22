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

FragTrap::FragTrap(std::string name) : _maxHP(100), _HP(100), _maxEnergy(100),  _Energy(100),  _level(1), _name(name), _meleeDamage(30),  _distDamage(20), _armor(5)
{
	srand(time(0));
	std::cout << "IT IS ALIIIIVE ! Wait, am I ?" << std::endl;
}

FragTrap::FragTrap(FragTrap const &ref)
{
	*this = ref;
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

void		FragTrap::rangedAttack(std::string const &target) const
{
	std::cout << "FR4G-TR " << this->_name << " attacks " << target << " from a certain distance, obviously, dealing " << this->_distDamage << " damage !" << std::endl;
}

void		FragTrap::meleeAttack(std::string const &target) const
{
	std::cout << "FR4G-TR " << this->_name << " orders his \"friends\" to attack " << target << " from a no distance, obviously, dealing " << this->_meleeDamage << " damage !" << std::endl;
}

void		FragTrap::takeDamage(unsigned int amount)
{
	int		i;

	if (this->_HP == 0)
	{
		std::cout << "I'M ALREADY DEAD STOP IT !" << std::endl;
		return ;
	}
	if ((int)amount <= this->_armor)
		amount = 0;
	else
		amount -= 5;
	i = amount;
	if ((int)amount > this->_HP)
		i = this->_HP;
	this->_HP -= amount;
	if (this->_HP < 0)
		this->_HP = 0;
	std::cout << "HEY ! Hit my minion, not me !\nFR4G-TR " << this->_name << " just go hit for " << i;
	if (this->_HP == 0)
		std::cout << " and died during the process by the way";
	std::cout << std::endl;
}

void		FragTrap::beRepaired(unsigned int amount)
{
	int		i;

	i = amount;
	if (this->_HP + amount > 100)
		i = this->_maxHP - this->_HP;
	this->_HP += amount;
	if (this->_HP > this->_maxHP)
		this->_HP = this->_maxHP;
	std::cout << "Aaaah... Nothing better than a glass of champagne brought by my most loyal minion directly in my hot tub !\nFR4G-TR " << this->_name << " just healed for " << i << std::endl;
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

int			FragTrap::getHP()
{
	return (this->_HP);
}

int			FragTrap::getEnergy()
{
	return (this->_Energy);
}
