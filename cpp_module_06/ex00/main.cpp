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

#include <limits.h>
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <cctype>
#include <sstream>

void	error_handling(std::exception &e)
{
	std::cout << "Error: Impossible conversion because: " << e.what() << std::endl;
}

void	ft_convert_tochar(double nb)
{
	std::cout << "char: ";
	if (nb > 255 || nb < 0 || isnan(nb))
		std::cout << "Impossible" << std::endl;
	else if (!std::isprint(nb))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << static_cast<unsigned char>(nb) << "\'" << std::endl;
}

void	ft_convert_toint(double nb)
{
	std::cout << "int: ";
	if (nb > INT_MAX || nb < INT_MIN || isnan(nb) || isinf(nb))
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(nb) << std::endl;
}

void	ft_convert_tofloat(double nb)
{
	std::cout << "float: ";
	if (isinf(nb))
	{
		if (nb < 0)
			std::cout << "-inff" << std::endl;
		else
			std::cout << "inff" << std::endl;
	}
	else if (isnan(nb))
		std::cout << "nanf" << std::endl;
	else
		std::cout << static_cast<float>(nb) << "f" << std::endl;	
}

void	ft_convert_todouble(double nb)
{
	std::cout << "double: ";
	if (isinf(nb))
	{
		if (nb < 0)
			std::cout << "-inf" << std::endl;
		else
			std::cout << "inf" << std::endl;
	}
	else if (isnan(nb))
		std::cout << "nan" << std::endl;
	else
		std::cout << nb << std::endl;	
}

void	ft_convert(char *str)
{
	double		nb;
	int			start;
	int			size;

	start = 0;
	size = 0;
	while (str[start] && std::isspace(str[start]))
		++start;
	while (str[start + size] && !std::isspace(str[start + size]))
		++size;
	std::string	string(str, start, size);
	try
	{
		nb = std::stod(str);
	}
	catch(std::exception& e)
	{
		error_handling(e);
		return ;
	}
	ft_convert_tochar(nb);
	ft_convert_toint(nb);
	ft_convert_tofloat(nb);
	ft_convert_todouble(nb);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: 1 argument neccessary." << std::endl;
		return (-1);
	}
	else
		ft_convert(av[1]);
	return (0);
}
