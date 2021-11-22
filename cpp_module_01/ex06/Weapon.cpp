/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 14:46:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/15 14:16:43 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str) : _type(str)
{
	std::cout << "Weapon of type : " << this->_type << " created." << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon of type : " << this->_type << " destroyed." << std::endl;
	return ;
}

const std::string		&Weapon::getType(void) const
{
	std::string const	&ref = _type;

	return (ref);
}

void			Weapon::setType(std::string str)
{
	this->_type = str;
	return ;
}
