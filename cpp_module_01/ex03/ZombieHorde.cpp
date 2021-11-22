/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 14:46:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/15 14:16:43 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include "Zombie.hpp"

ZombieHorde::ZombieHorde(int n)
{
	int		i;

	srand(time(0));
	i = -1;
	this->_zombietype = "Classic";
	this->_horde = new Zombie*[n + 1];
	std::cout << "A horde is growing..." << std::endl;
	while (++i < n)
		this->_horde[i] = randomChump();
	this->_horde[i] = NULL;
	return ;
}	

ZombieHorde::~ZombieHorde()
{
	int		i;

	i = -1;
	while (this->_horde[++i] != NULL)
		delete this->_horde[i];
	delete this->_horde;
	std::cout << "The horde disappeared in the shadows..." << std::endl;
}

Zombie	*ZombieHorde::NewZombie(std::string name) const
{
	Zombie	*newzombie;

	newzombie = new Zombie(this->_zombietype, name);
	return (newzombie);
}

Zombie	*ZombieHorde::randomChump(void) const
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
	return (zombie);
}

void	ZombieHorde::announce(void) const
{
	int		i;

	i = -1;
	while (this->_horde[++i] != NULL)
		this->_horde[i]->annonce();
	return ;
}
