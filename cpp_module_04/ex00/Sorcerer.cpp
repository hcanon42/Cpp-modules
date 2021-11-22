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

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string type) : _name(name), _type(type)
{
	std::cout << this->_name << ", " << this->_type << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &ref)
{
	*this = ref;
	std::cout << this->_name << ", " << this->_type << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->_name << ", " << this->_type << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer	&Sorcerer::operator=(Sorcerer const &rhs)
{
	this->_name = rhs._name;
	this->_type = rhs._type;
	return (*this);
}

std::string		Sorcerer::getName() const
{
	return (this->_name);
}

void			Sorcerer::setName(std::string name)
{
	this->_name = name;
}

std::string		Sorcerer::getType() const
{
	return (this->_type);
}

void			Sorcerer::setType(std::string type)
{
	this->_type = type;
}

void			Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}

std::ostream	&operator<<(std::ostream &o, Sorcerer const &sorcerer)
{
	o << "I am " << sorcerer.getName() << ", " << sorcerer.getType() << ", and I like ponies!" << std::endl;
	return (o);
}
