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

Form::Form() : _name("Form"), _signed(0), _minGradeToBeSigned(150), _minGradeToBeExecuted(150)
{
}

Form::Form(std::string name, int gradeSigned, int gradeExecuted) : _name(name), _signed(0), _minGradeToBeSigned(check_grade(gradeSigned)), _minGradeToBeExecuted(check_grade(gradeExecuted))
{
}

Form::Form(Form const &ref) : _name(ref._name), _signed(ref._signed), _minGradeToBeSigned(ref._minGradeToBeSigned), _minGradeToBeExecuted(ref._minGradeToBeExecuted)
{
}

Form::~Form()
{
}

Form				&Form::operator=(Form const &rhs)
{
	this->_signed = rhs._signed;
	return (*this);
}

std::string const	Form::getName(void) const
{
	return (this->_name);
}

bool				Form::getBool(void) const
{
	return (this->_signed);
}

int					Form::getGradeSigned(void) const
{
	return (this->_minGradeToBeSigned);
}

int					Form::getGradeExecuted(void) const
{
	return (this->_minGradeToBeExecuted);
}

int					Form::check_grade(int grade) const
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	else
		return (grade);
}

void				Form::getSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeSigned())
		throw Form::GradeTooLowException();
	else
	{
		this->_signed = 1;
	}
}

const char			*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low !");
}

const char			*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high !");
}

std::ostream		&operator<<(std::ostream &out, Form const &form)
{
	std::cout << form.getName() << " is " << ((form.getBool() == 0) ? "an unsigned" : "a signed") << " Form, needing a grade " << form.getGradeSigned() << " to be signed and a grade " << form.getGradeExecuted() << " to be executed.";
	return (out);
}
