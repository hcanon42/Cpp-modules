/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 14:46:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/15 14:16:43 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string type, std::string name) : _name(name), _type(type)
{
	this->advert();
	std::cout << "(The zombie just got created)" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "bweeeeaaaaaaaarrr... (the zombie just died)" << std::endl;
}

void	Zombie::advert(void) const
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiinnnnnnssss..." << std::endl;
}

void	Zombie::annonce(void) const
{
	std::cout << "raaaaauuuuuuuuughhhhh, me is " << this->_name << " a " << this->_type << " Zombie" << std::endl;
}
