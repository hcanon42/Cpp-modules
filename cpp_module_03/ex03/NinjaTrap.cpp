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

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(60, 60, 120, 120, 1, name, 60, 5, 0, (std::string)"N1NJ4-TR")
{
	std::cout << "POUF ! A robot in kimono just appeared from nowhere !" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &ref)
{
	*this = ref;
	this->_type = "N1NJ4-TR";
	std::cout << "OMG ! The ninja cloned himself like Naruto !" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "The ninja disappeared in a smoke bomb ! He left a stick, don't ask me why..." << std::endl;
}

NinjaTrap	&NinjaTrap::operator=(NinjaTrap const &rhs)
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

void		NinjaTrap::ninjaShoebox(ClapTrap const &clap)
{

	if (this->_Energy < 25)
	{
		std::cout << "My psychic powers have been expanded ! I gotta eat ramens and meditate before going again." << std::endl;
		return ;
	}
	(void)clap;
	this->_Energy -= 25;
	std::cout << "Hello ancestor. Let me show you the strength you tought me ! He then tries to clim a tree, but fails miserably, for it is difficult with a big wheel instead of legs..." << std::endl;
}

void		NinjaTrap::ninjaShoebox(ScavTrap const &scav)
{

	if (this->_Energy < 25)
	{
		std::cout << "My psychic powers have been expanded ! I gotta eat ramens and meditate before going again." << std::endl;
		return ;
	}
	(void)scav;
	this->_Energy -= 25;
	std::cout << "SC4V-TR, your discipline and fervor towards the opening of doors is examplary, we could all learn from you." << std::endl;
}

void		NinjaTrap::ninjaShoebox(FragTrap const &frag)
{

	if (this->_Energy < 25)
	{
		std::cout << "My psychic powers have been expanded ! I gotta eat ramens and meditate before going again." << std::endl;
		return ;
	}
	(void)frag;
	this->_Energy -= 25;
	std::cout << "FR4G-TR, you world destructor ! I will kill you ! FOR MIYAZAKIIIIII !!" << std::endl;
}

void		NinjaTrap::ninjaShoebox(NinjaTrap const &ninja)
{

	if (this->_Energy < 25)
	{
		std::cout << "My psychic powers have been expanded ! I gotta eat ramens and meditate before going again." << std::endl;
		return ;
	}
	(void)ninja;
	this->_Energy -= 25;
	std::cout << "I salute you, otaku brother. I hope you read the last \"My Hero Academia\", otherwise you won't be mmy brother anymore !" << std::endl;
}
