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

#include "Brain.hpp"

Brain::Brain(void) : _neurons(86)
{
	std::stringstream	tmp;

	tmp << this;
	this->_address = tmp.str();
	std::cout << "Brain created. It has " << this->_neurons << " 000 000 neurons by the way." << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destroyed" << std::endl;
}

std::string		Brain::identify(void) const
{
	return (this->_address);
}
