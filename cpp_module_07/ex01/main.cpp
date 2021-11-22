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

#include "iter.hpp"

template<typename T>
void	ft_print(T elem)
{
	std::cout << *elem << std::endl;
}

template<typename T>
T		*allocate(T elem)
{
	return (new T(elem));
}

int		main( void )
{
	int 		**a;
	std::string	**b;

	std::cout << std::endl << "Allocating int tab..." << std::endl << std::endl;
	a = new int*[5];
	a[0] = allocate(42);
	a[1] = allocate(12);
	a[2] = allocate(23);
	a[3] = allocate(34);
	a[4] = allocate(42);
	iter(a, 5, &ft_print);

	std::cout << std::endl << "Allocating string tab..." << std::endl << std::endl;
	b = new std::string*[3];
	b[0] = allocate(static_cast<std::string>("Bonjour"));
	b[1] = allocate(static_cast<std::string>("Je suis"));
	b[2] = allocate(static_cast<std::string>("rigolo !"));
	iter(b, 3, &ft_print);

	delete a[0];
	delete a[1];
	delete a[2];
	delete a[3];
	delete a[4];
	delete b[0];
	delete b[1];
	delete b[2];
	delete a;
	delete b;

	return (0);
}