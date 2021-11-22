/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 14:46:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/15 14:16:43 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(void) : _legs(4), _head(1), _body(1)
{
	std::cout << "A Pony is born. A cute one by the way." << std::endl;
}

Pony::~Pony(void)
{
	std::cout << "A Pony died. Horribly." << std::endl;
}

void		Pony::doSomething(void) const
{
	std::cout << "This pony has " << this->_legs << " legs, " << this->_body << " body and " << this->_head << " head." << std::endl;
}
