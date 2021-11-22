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
#include <string>
#include <stdlib.h>
#include <time.h>

struct	Data
{
	std::string	s1;
	int			n;
	std::string	s2;
};

void	*serialize(void)
{
	const char	alpha[] = "azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN1324567890";
	char		*address = new char[20];
	int			i;

	i = -1;
	while (++i < 8)
		address[i] = alpha[rand() % 62];
	*reinterpret_cast<int *>(address + 8) = std::rand();
	i = 11;
	while (++i < 20)
		address[i] = alpha[rand() % 62];
	return (reinterpret_cast<void *>(address));
}

Data	*deserialize(void *raw)
{
	Data	*data;

	data = new Data;
	data->s1 = std::string(reinterpret_cast<char *>(raw), 0, 8);
	data->n = *reinterpret_cast<int *>(reinterpret_cast<char *>(raw) + 8);
	data->s2 = std::string(reinterpret_cast<char *>(raw), 12, 20);
	return (data);
}

int		main()
{
	void		*address;
	Data		*data;

	srand(time(0));
	std::cout << std::endl << "Creating random Sequence..." << std::endl;
	address = serialize();
	std::cout << "random Sequence created ! address at --> " << address << std::endl << std::endl;

	std::cout << "Calling deserialize() function..." << std::endl;
	data = deserialize(address);
	std::cout << "Data collected !" << std::endl << std::endl;

	std::cout << "data->s1 = \"" << data->s1 << "\"" << std::endl;
	std::cout << "data->n = " << data->n << std::endl;
	std::cout << "data->s2 = \"" << data->s2 << "\"" << std::endl;
	return (0);
}
