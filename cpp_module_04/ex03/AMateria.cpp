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

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _xp(0), _type(type)
{
}

AMateria::AMateria(AMateria const &ref)
{
	*this = ref;
}

AMateria::~AMateria()
{
}

AMateria			&AMateria::operator=(AMateria const &rhs)
{
	this->_xp = rhs.getXP();
	this->_type = rhs.getType();
	return (*this);
}

std::string const	&AMateria::getType() const
{
	return (this->_type);
}

void				AMateria::setXP(unsigned int xp)
{
	this->_xp = xp;
}

unsigned int		AMateria::getXP() const
{
	return (_xp);
}

void				AMateria::use(ICharacter &target)
{
	(void)target;
	this->_xp += 10;
}
