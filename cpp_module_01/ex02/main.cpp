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

#include "ZombieEvent.hpp"

int		main(void)
{
	ZombieEvent	event;
	Zombie		*zombie;

	std::cout << std::endl << "Zombie type set to Classic" << std::endl << std::endl;
	event.setZombieType("Classic");
	zombie = event.NewZombie("Marc");
	delete zombie;
	zombie = event.randomChump();
	delete zombie;
	std::cout << std::endl << "Zombie type set to Superior" << std::endl << std::endl;
	event.setZombieType("Superior");
	zombie = event.randomChump();
	delete zombie;
	zombie = event.randomChump();
	delete zombie;
	return (0);
}
