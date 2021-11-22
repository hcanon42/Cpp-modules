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

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int		ft_sed(std::string filename, std::string replacefile, std::string tofind, std::string replacing)
{
	std::ifstream				input(filename);
	std::string					buffer;
	std::string::size_type		n;

	if (input.fail())
	{
		std::cout << std::endl << "Error: entryfile cannot be read: " << filename << std::endl << std::endl;
		return (-1);
	}
	std::ofstream				output(replacefile);
	if (output.fail())
	{
		std::cout << std::endl << "Error: outputfile cannot be created: " << replacefile << std::endl << std::endl;
		return (-1);
	}
	while (std::getline(input, buffer))
	{
		n = buffer.find(tofind);
		while (n != std::string::npos)
		{
			buffer.replace(n, tofind.size(), replacing);
			n = buffer.find(tofind, n + replacing.size());
		}
		output << buffer;
		if (buffer.size() > 0)
			output << std::endl;
	}
	input.close();
	output.close();
	return (0);
}

int		main(int ac, char **av)
{
	int		exit;

	if (ac != 4)
	{
		std::cout << std::endl << "Error: must have 3 arguments: namefile -- to_replace_str -- replacing_str" << std::endl << std::endl;
		return (-1);
	}
	if (!strlen(av[2]) || !strlen(av[3]))
	{
		std::cout << std::endl << "Error: Strings should not be empty." << std::endl << std::endl;
		return (-1);
	}
	exit = ft_sed((std::string)av[1], (std::string)av[1] + ".replace", (std::string)av[2], (std::string)av[3]);
	return (exit);
}