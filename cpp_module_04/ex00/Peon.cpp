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

#include "Peon.hpp"
#include "Victim.hpp"

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &ref) : Victim(ref)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon	&Peon::operator=(Peon const &rhs)
{
	this->setName(rhs.getName());
	return (*this);
}

void			Peon::getPolymorphed() const
{
	std::cout << this->getName() << " was just polymorphed into a pink pony!" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Peon const &peon)
{
	o << peon.getName() << " not happy!" << std::endl;
	return (o);
}