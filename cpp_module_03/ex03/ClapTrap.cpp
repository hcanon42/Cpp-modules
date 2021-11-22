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

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Oh no, another CL4P-TR just got created..." << std::endl;
}

ClapTrap::ClapTrap(int maxHP, int HP, int maxEnergy, int Energy, int lvl, std::string name, int meleeDamage, int distDamage, int armor, std::string type)
{
	this->_maxHP = maxHP;
	this->_HP = HP;
	this->_maxEnergy = maxEnergy;
	this->_Energy = Energy;
	this->_level = lvl;
	this->_name = name;
	this->_meleeDamage = meleeDamage;
	this->_distDamage = distDamage;
	this->_armor = armor;
	this->_type = type;
	std::cout << "Oh no, another CL4P-TR just got created..." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &ref)
{
	*this = ref;
	std::cout << "Another robotic imp just got duplicated !" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_type << " " << this->_name << " finally died, for the good of every one !" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
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

void		ClapTrap::rangedAttack(std::string const &target) const
{
	if (this->_type.compare("FR4G-TR") == 0)
		std::cout << this->_type << " " << this->_name << " attacks " << target << " from a certain distance, obviously, dealing " << this->_distDamage << " damage !" << std::endl;
	else if (this->_type.compare("SC4V-TR") == 0)
		std::cout << this->_type << " " << this->_name << " attacks " << target << " by throwing pebbles and hiding, dealing " << this->_distDamage << " damage !" << std::endl;
	else
		std::cout << this->_type << " " << this->_name << " is throwing all sort of things at " << target << " such as chopsticks, orphans, or administrative papers, dealing " << this->_distDamage << " damage !" << std::endl;
}

void		ClapTrap::meleeAttack(std::string const &target) const
{
	if (this->_type.compare("FR4G-TR") == 0)
		std::cout << this->_type << " " << this->_name << " orders his \"friends\" to attack " << target << " from a no distance, obviously, dealing " << this->_meleeDamage << " damage !" << std::endl;
	else if (this->_type.compare("SC4V-TR") == 0)
		std::cout << this->_type << " " << this->_name << " attacks shyly " << target << " dealing " << this->_meleeDamage << " damage !" << std::endl;
	else
		std::cout << this->_type << " " << this->_name << " attacks " << target << " while screaming \"YATAAAAAAA\" dealing " << this->_meleeDamage << " damage !" << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	int		i;

	if (this->_HP == 0)
	{
		if (this->_type.compare("FR4G-TR") == 0)
			std::cout << "I'M ALREADY DEAD STOP IT !" << std::endl;
		else if (this->_type.compare("SC4V-TR") == 0)
			std::cout << "Please stop hurting me I'm useless already..." << std::endl;
		else
			std::cout << "PLEASE STOP ! I can offer you places at the JapanExpo !" << std::endl;
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
	if (this->_type.compare("FR4G-TR") == 0)
		std::cout << "HEY ! Hit my minion, not me !\n" << this->_type << " " << this->_name << " just go hit for " << i;
	else if (this->_type.compare("SC4V-TR") == 0)
		std::cout << "Argh... It must be deserved, I guess...\n" << this->_type << " " << this->_name << " just go hit for " << i;
	else
		std::cout << "Aaha the power of friendship protects me, fiend ! You will never beat me !\n" << this->_type << " " << this->_name << " just go hit for " << i;
	if (this->_HP == 0)
		std::cout << " and died during the process by the way";
	std::cout << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	int		i;

	i = amount;
	if (this->_HP + amount > (unsigned)this->_maxHP)
		i = this->_maxHP - this->_HP;
	this->_HP += amount;
	if (this->_HP > this->_maxHP)
		this->_HP = this->_maxHP;
	if (this->_type.compare("FR4G-TR") == 0)
		std::cout << "Aaaah... Nothing better than a glass of champagne brought by my most loyal minion directly in my hot tub !\n" << this->_type << " " << this->_name << " just healed for " << i << std::endl;
	else if (this->_type.compare("SC4V-TR") == 0)
		std::cout << "Aw thank you ! I can offer you to hold the door if you want !\n" << this->_type << " " << this->_name << " just healed for " << i << std::endl;
	else
		std::cout << "Thank you otaku friend, let the shônen God guide you.\n" << this->_type << " " << this->_name << " just healed for " << i << std::endl;
}

int			ClapTrap::getHP() const
{
	return (this->_HP);
}

int			ClapTrap::getEnergy() const
{
	return (this->_Energy);
}

