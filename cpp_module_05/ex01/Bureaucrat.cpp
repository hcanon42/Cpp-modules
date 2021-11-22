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

Bureaucrat::Bureaucrat() : _name("Marc"), _grade(150)
{
}

Bureaucrat::Bureaucrat(int grade) : _name("Marc")
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &ref)
{
	*this = ref;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat			&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_grade = rhs._grade;
	return (*this);
}

std::string			Bureaucrat::getName(void) const
{
	return (this->_name);
}

int					Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void				Bureaucrat::getPromoted(void)
{
	if (this->getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void				Bureaucrat::getDowngraded(void)
{
	if (this->getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void				Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.getSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " cannot sign " << form.getName() << " because : " << e.what() << std::endl;
	}
}

const char			*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low !");
}

const char			*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high !");
}

std::ostream		&operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	std::cout << bureaucrat.getName() << ", Bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}
