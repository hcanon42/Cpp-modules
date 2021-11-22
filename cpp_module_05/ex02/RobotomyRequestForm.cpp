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

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form(static_cast<std::string>("RobotomyRequestForm"), 72, 45), _target("Target")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(static_cast<std::string>("RobotomyRequestForm"), 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ref) : Form(ref.getName(), ref.getGradeSigned(), ref.getGradeExecuted())
{
	this->_target = ref.getTarget();
	this->setBool(ref.getBool());
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm		&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	this->setBool(rhs.getBool());
	this->_target = rhs.getTarget();
	return (*this);
}

std::string				RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void					RobotomyRequestForm::proceedAction(void) const
{
	std::cout << "BZZZZzzzzz - rizzzzzZZZzzz" << std::endl;
	std::cout << this->getTarget() << " has been successfully robotomized !" << std::endl;
}
