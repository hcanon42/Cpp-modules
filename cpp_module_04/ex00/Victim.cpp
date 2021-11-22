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

#include "Victim.hpp"

Victim::Victim(std::string name) : _name(name)
{
	std::cout << "A random victim called " << this->_name << " just appeared!" << std::endl;
}

Victim::Victim(Victim const &ref)
{
	*this = ref;
	std::cout << "A random victim called " << this->_name << " just appeared!" << std::endl;
}

Victim::~Victim()
{
	std::cout << "The victim " << this->_name << " died for no apparent reasons!" << std::endl;
}

Victim	&Victim::operator=(Victim const &rhs)
{
	this->_name = rhs._name;
	return (*this);
}

std::string		Victim::getName() const
{
	return (this->_name);
}

void			Victim::setName(std::string name)
{
	this->_name = name;
}

void			Victim::getPolymorphed() const
{
	std::cout << this->getName() << " was just polymorphed in a cute little sheep!" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Victim const &victim)
{
	o << "I'm " << victim.getName() << " and I like otters!" << std::endl;
	return (o);
}
