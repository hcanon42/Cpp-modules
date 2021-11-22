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

#include "ZombieHorde.hpp"

void	test_horde()
{
	ZombieHorde horde(15);

	horde.announce();
	return ;
}

int		main(void)
{
	std::cout << std::endl << "Entering test..." << std::endl << std::endl;
	test_horde();
	std::cout << std::endl << "Exiting test..." << std::endl << std::endl;
	return (0);
}
