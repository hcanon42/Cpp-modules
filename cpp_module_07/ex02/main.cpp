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

#include "Array.tpp"

int		main( void )
{
	Array<int>			int_tab(5);
	Array<std::string>	string_tab(3);

	std::cout << "Filling int_tab..." << std::endl;
	int_tab[0] = 42;
	int_tab[1] = 12;
	int_tab[2] = 23;
	int_tab[3] = 34;
	int_tab[4] = 42;
	std::cout << "Printing int_tab : " << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "int_tab[" << i << "] = " << int_tab[i] << std::endl;

	Array<int>			copy_int_tab(int_tab);
	std::cout << std::endl << "Printing cpy_int_tab : " << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "cpy_int_tab[" << i << "] = " << copy_int_tab[i] << std::endl;


	std::cout << std::endl << "Filling string_tab..." << std::endl;
	string_tab[0] = std::string("bonjour");
	string_tab[1] = std::string("je suis");
	string_tab[2] = std::string("rigolo");
	std::cout << "Printing string_tab : " << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << "string_tab[" << i << "] = " << string_tab[i] << std::endl;

	Array<std::string>	copy_string_tab;
	copy_string_tab = string_tab;
	std::cout << std::endl << "Printing cpy_string_tab : " << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << "cpy_string_tab[" << i << "] = " << copy_string_tab[i] << std::endl;

	try
	{
		std::cout << std::endl << "Trying out of range index..." << std::endl;
		int_tab[1258] = 8;
		std::cout << std::endl << "All went fine : it is not good..." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}