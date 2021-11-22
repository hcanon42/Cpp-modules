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

#include "Human.hpp"


Human::Human(void)
{
	std::cout << "Human is born" << std::endl;
}

Human::~Human(void)
{
	std::cout << "Human died" << std::endl;
}

Brain	Human::getBrain(void) const
{
	return (this->_brain);
}

std::string		Human::identify(void) const
{
	return (this->_brain.identify());
}
