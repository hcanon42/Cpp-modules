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

#include "easyfind.hpp"

int		main()
{
	std::vector<int>	lst;

	lst.push_back(42);
	lst.push_back(12);
	lst.push_back(1);
	lst.push_back(23);
	lst.push_back(58);
	lst.push_back(24);
	lst.push_back(20);
	lst.push_back(31);
	lst.push_back(8);
	lst.push_back(98);
	lst.push_back(13546);
	lst.push_back(61);
	lst.push_back(12);
	lst.push_back(52);
	lst.push_back(42);
	std::cout << "Int vector initialized !" << std::endl;
	std::cout << "Tring to find 42... --> ";
	try
	{
		std::cout << easyfind(lst, 42) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Tring to find 0(non existant)... --> ";
	try
	{
		std::cout << easyfind(lst, 0) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Tring to find 13546... --> ";
	try
	{
		std::cout << easyfind(lst, 13546) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Tring to find 52... --> ";
	try
	{
		std::cout << easyfind(lst, 52) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
