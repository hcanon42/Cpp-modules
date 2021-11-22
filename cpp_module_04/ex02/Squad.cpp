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

#include "Squad.hpp"
#include <stdlib.h>

Squad::Squad() : _units(NULL), _count(0)
{
}

Squad::Squad(Squad const &ref) : _units(NULL), _count(0)
{
	int		i;

	i = -1;
	while (++i < ref.getCount())
		push(ref.getUnit(i)->clone());
}

Squad::~Squad()
{
	Units	*unit;
	Units	*tmp;

	unit = this->_units;
	while (unit)
	{
		tmp = unit;
		unit = unit->getNext();
		delete tmp;
	}
}

Squad			&Squad::operator=(Squad const &rhs)
{
	Units	*unit;
	Units	*tmp;
	int		i;

	i = -1;
	unit = this->_units;
	while (unit)
	{
		tmp = unit;
		unit = unit->getNext();
		delete tmp;
	}
	this->_units = NULL;
	this->_count = 0;
	while (++i < rhs.getCount())
		push(rhs.getUnit(i)->clone());
	return (*this);
}

int				Squad::getCount() const
{
	return (this->_count);
}

ISpaceMarine	*Squad::getUnit(int n) const
{
	Units	*unit = _units;
	int		i;

	if (n < 0 || n >= this->_count)
		return (NULL);
	i = -1;
	unit = this->_units;
	while (++i < n)
		unit = unit->getNext();
	return (unit->getUnit());
}

int				Squad::push(ISpaceMarine* unit)
{
	Units	*curr_unit;

	if (!unit)
		return (0);
	if (!this->_units)
	{
		this->_units = new Units(unit);
		this->_count = 1;
		return (1);
	}
	curr_unit = this->_units;
	while (curr_unit->getNext())
	{
		if (curr_unit->getUnit() == unit)
			return (0);
		curr_unit = curr_unit->getNext();
	}
	if (curr_unit->getUnit() == unit)
		return (0);
	curr_unit->setNext(new Units(unit));
	this->_count++;
	return (1);
}

//-------------------UNITS----------------------

Units::Units(ISpaceMarine* unit) : _unit(unit)
{
	this->_next = NULL;
}

Units::Units(Units const &ref)
{
	*this = ref;
}

Units::~Units()
{
	delete this->_unit;
}

Units				&Units::operator=(Units const &rhs)
{
	this->_next = rhs.getNext();
	this->_unit = rhs.getUnit();
	return (*this);
}

Units				*Units::getNext() const
{
	return (this->_next);
}

ISpaceMarine		*Units::getUnit() const
{
	return (this->_unit);
}

void				Units::setNext(Units* next)
{
	this->_next = next;
}

void				Units::setUnit(ISpaceMarine* unit)
{
	this->_unit = unit;
}
