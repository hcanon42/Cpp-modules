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
#include "Form.hpp"

int		main()
{
	std::cout << "-----------------CREATING BUREAUCRATS------------------" << std::endl << std::endl;
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
	std::cout << "-----------------PROMOTING BUREAUCRATS------------------" << std::endl << std::endl;
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
	std::cout << "-----------------DOWNGRADING BUREAUCRATS------------------" << std::endl << std::endl;
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
		std::cout << "Bureaucrat of grade 150 just got downgraded ? --> " << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl << std::endl;
	}
	std::cout << "-----------------CREATING FORMS------------------" << std::endl << std::endl;
	try
	{
		Form	formA("Annoying Form", 15, 25);
		std::cout << "A form just got created ! --> " << formA << std::endl;

		Form   formB("Super long Form", 1, 150);
		std::cout << "A form just got created ! --> " << formB << std::endl;

		Form	formC("Impossible Form", -1, 151);
		std::cout << "A form just got created ! --> " << formC << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl << std::endl;
	}
	std::cout << "-----------------SIGNING FORMS------------------" << std::endl << std::endl;
	try
	{
		Form		forma("Annoying Form", 25, 25);
		std::cout << "A form just got created ! --> " << forma << std::endl;

		Form		formb("Super long Form", 75, 25);
		std::cout << "A form just got created ! --> " << formb << std::endl;

		Bureaucrat	bureaucrat(50);
		std::cout << "A bureaucrat just got created ! --> " << bureaucrat << std::endl <<std::endl;

		std::cout << bureaucrat.getName() << " is trying to sign " << forma.getName() << "..." << std::endl;
		bureaucrat.signForm(forma);
		std::cout << bureaucrat.getName() << " is trying to sign " << formb.getName() << "..." << std::endl;
		bureaucrat.signForm(formb);

		std::cout << std::endl << forma << std::endl;
		std::cout << formb << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl << std::endl;
	}
	return (0);
}
