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

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	int		i;

	i = -1;
	while (++i < 4)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &ref)
{
	int		i;

	i = -1;
	while (++i < 4)
		this->_materias[i] = NULL;
	*this = ref;
}

MateriaSource::~MateriaSource()
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (j != i && this->_materias[i] == this->_materias[j])
				this->_materias[j] = NULL;
	}
	i = -1;
	while (++i < 4)
		if (this->_materias[i])
			delete this->_materias[i];
}

MateriaSource			&MateriaSource::operator=(MateriaSource const &rhs)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (this->_materias[i])
			delete this->_materias[i];
		if (!rhs.getMateria(i))
			this->_materias[i] = NULL;
		else
			this->_materias[i] = rhs.getMateria(i)->clone();
	}
	return (*this);
}



void					MateriaSource::learnMateria(AMateria *m)
{
	int		i;

	if (!m)
		return;
	i = -1;
	while (++i < 4)
	{
		if (!this->_materias[i])
		{
			this->_materias[i] = m;
			break ;
		}
	}
}

AMateria				*MateriaSource::createMateria(std::string const &type)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	return NULL;
}

AMateria				*MateriaSource::getMateria(int i) const
{
	if (i < 0 || i > 3)
		return (NULL);
	return (this->_materias[i]);
}
