/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 14:46:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/15 14:16:43 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
{
	srand(time(0));
}

ZombieEvent::~ZombieEvent(void)
{
}

void	ZombieEvent::setZombieType(std::string type)
{
	this->_zombietype = type;
	return ;
}

Zombie	*ZombieEvent::NewZombie(std::string name) const
{
	Zombie	*newzombie;

	newzombie = new Zombie(this->_zombietype, name);
	return (newzombie);
}

Zombie	*ZombieEvent::randomChump(void) const
{
	int				i;
	Zombie			*zombie;
	std::string		name;

	i = rand() % 6;
	if (i == 0)
		name = "Bleeeeaaaarrrr";
	else if (i == 1)
		name = "Louis";
	else if (i == 2)
		name = "Jimmy el gringo";
	else if (i == 3)
		name = "Qiqi";
	else if (i == 4)
		name = "Looser";
	else if (i == 5)
		name = "Jesus";
	zombie = NewZombie(name);
	zombie->annonce();
	return (zombie);
}
