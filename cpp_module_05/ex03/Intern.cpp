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

#include "Intern.hpp"

Intern::Intern()
{
	_knownForms[0] = "shrubbery form";
	_knownConstructor[0] = ShrubberyCreationForm::constructor;
	_knownForms[1] = "robotomy form";
	_knownConstructor[1] = RobotomyRequestForm::constructor;
	_knownForms[2] = "presidential form";
	_knownConstructor[2] = PresidentialPardonForm::constructor;
}

Intern::Intern(Intern const &ref)
{
	_knownForms[0] = "shrubbery form";
	_knownConstructor[0] = ShrubberyCreationForm::constructor;
	_knownForms[1] = "robotomy form";
	_knownConstructor[1] = RobotomyRequestForm::constructor;
	_knownForms[2] = "presidential form";
	_knownConstructor[2] = PresidentialPardonForm::constructor;
	(void)ref;
}

Intern::~Intern()
{
}

Intern			&Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

Form			*Intern::makeForm(std::string name, std::string target)
{
	int		i;

	i = -1;
	while (++i < 3)
		if (name.compare(this->_knownForms[i]) == 0)
			return (_knownConstructor[i](target));
	throw Intern::UnknownFormException();
	return (NULL);
}

const char		*Intern::UnknownFormException::what() const throw()
{
	return ("Unknown form name");
}
