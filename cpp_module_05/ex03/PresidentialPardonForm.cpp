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

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form(static_cast<std::string>("PresidentialPardonForm"), 25, 5), _target("Target")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(static_cast<std::string>("PresidentialPardonForm"), 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ref) : Form(ref.getName(), ref.getGradeSigned(), ref.getGradeExecuted())
{
	this->_target = ref.getTarget();
	this->setBool(ref.getBool());
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm		&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	this->setBool(rhs.getBool());
	this->_target = rhs.getTarget();
	return (*this);
}

std::string				PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

Form					*PresidentialPardonForm::constructor(std::string target)
{
	return (new PresidentialPardonForm(target));
}

void					PresidentialPardonForm::proceedAction(void) const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox !" << std::endl;
}
