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

#include "Pony.hpp"

void	ponyOnTheHeap(void)
{
	Pony	*poney;

	std::cout << "There is no Pony yet" << std::endl;
	poney = new Pony;
	poney->doSomething();
	delete poney;
	std::cout << "The Pony disappeared. I repeat, the Pony disappeared." << std::endl;
	return ;
}

void	ponyOnTheStack(void)
{
	Pony	SinglePony;

	std::cout << "A Pony just got declared." << std::endl;
	SinglePony.doSomething();
	std::cout << "The function will end on the very next line." << std::endl;
	return ;
}

int		main(void)
{
	std::cout << std::endl << "Entering ponyOnTheHeap()..." << std::endl;
	ponyOnTheHeap();
	std::cout << "Exiting ponyOnTheHeap()..." << std::endl << std::endl;

	std::cout << "Entering ponyOnTheStack()..." << std::endl;
	ponyOnTheStack();
	std::cout << "Exiting ponyOnTheStack()..." << std::endl << std::endl;

	return (0);
}
