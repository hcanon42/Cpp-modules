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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
		ShrubberyCreationForm	formA("target");
		std::cout << "A form just got created ! --> " << formA << std::endl;
		RobotomyRequestForm   	formB("target");
		std::cout << "A form just got created ! --> " << formB << std::endl;
		PresidentialPardonForm	formC("target");
		std::cout << "A form just got created ! --> " << formC << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl << std::endl;
	}
	std::cout << "-----------------SIGNING FORMS------------------" << std::endl << std::endl;
	try
	{
		PresidentialPardonForm		forma("Handsome Jack");
		std::cout << "A form just got created ! --> " << forma << std::endl;
		RobotomyRequestForm			formb("The guy from the movie Brazil");
		std::cout << "A form just got created ! --> " << formb << std::endl;

		Bureaucrat	bureaucrat(50);
		std::cout << "A bureaucrat just got created ! --> " << bureaucrat << std::endl <<std::endl;

		std::cout << bureaucrat.getName() << " is trying to sign " << forma.getName() << "..." << std::endl;
		bureaucrat.signForm(forma);
		std::cout << bureaucrat.getName() << " is trying to sign " << formb.getName() << "..." << std::endl;
		bureaucrat.signForm(formb);

		std::cout << std::endl << forma << std::endl;
		std::cout << formb << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl << std::endl;
	}
	std::cout << "-----------------EXECUTING FORMS------------------" << std::endl << std::endl;
	try
	{
		PresidentialPardonForm		forma("Handsome Jack");
		std::cout << "A form just got created ! --> " << forma << std::endl;
		RobotomyRequestForm			formb("The guy from the movie Brazil");
		std::cout << "A form just got created ! --> " << formb << std::endl;
		ShrubberyCreationForm		formc("house");
		std::cout << "A form just got created ! --> " << formc << std::endl << std::endl;

		Bureaucrat	bureaucrat(50);
		std::cout << "A bureaucrat just got created ! --> " << bureaucrat << std::endl;
		Bureaucrat	marc(4);
		std::cout << "A bureaucrat just got created ! --> " << marc << std::endl <<std::endl;

		marc.signForm(forma);
		marc.signForm(formb);
		marc.signForm(formc);

		std::cout << std::endl << marc.getName() << " is trying to execute " << forma.getName() << "..." << std::endl;
		marc.executeForm(forma);
		std::cout << std::endl << marc.getName() << " is trying to execute " << formb.getName() << "..." << std::endl;
		marc.executeForm(formb);
		std::cout << std::endl << marc.getName() << " is trying to execute " << formc.getName() << "..." << std::endl;
		marc.executeForm(formc);
		std::cout << std::endl << bureaucrat.getName() << " is trying to execute " << forma.getName() << "..." << std::endl;
		bureaucrat.executeForm(forma);

		std::cout << std::endl << forma << std::endl;
		std::cout << formb << std::endl;
		std::cout << formc << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl << std::endl;
	}
	return (0);
}
