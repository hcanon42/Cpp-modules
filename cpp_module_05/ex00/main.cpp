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

#include "Bureaucrat.hpp"

int		main()
{
	try
	{
		Bureaucrat	a(12);
		std::cout << "Bureaucrat of grade 12 created --> " << a << std::endl;
		Bureaucrat  b(150);
		std::cout << "Bureaucrat of grade 150 created --> " << b << std::endl;
		Bureaucrat  c(1);
		std::cout << "Bureaucrat of grade 1 created --> " << c << std::endl;
		Bureaucrat  d(0);
		std::cout << "Bureaucrat of grade 0 created --> " << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl << std::endl;
	}
	try
	{
		Bureaucrat	a(12);
		a.getPromoted();
		std::cout << "Bureaucrat of grade 12 just got promoted ! --> " << a << std::endl;

		Bureaucrat  b(150);
		b.getPromoted();
		std::cout << "Bureaucrat of grade 150 just got promoted ! --> " << b << std::endl;

		Bureaucrat  c(1);
		c.getPromoted();
		std::cout << "Bureaucrat of grade 1 just got promoted ? --> " << c << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl << std::endl;
	}
	try
	{
		Bureaucrat	a(12);
		a.getDowngraded();
		std::cout << "Bureaucrat of grade 12 just got downgraded ! --> " << a << std::endl;

		Bureaucrat  b(1);
		b.getDowngraded();
		std::cout << "Bureaucrat of grade 1 just got downgraded ! --> " << b << std::endl;

		Bureaucrat  c(150);
		c.getDowngraded();
		std::cout << "Bureaucrat of grade 1 just got downgraded ? --> " << c << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl << std::endl;
	}
	return (0);
}
