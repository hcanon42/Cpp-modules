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

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form(static_cast<std::string>("SchrubberyCreationForm"), 145, 137), _target("Target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form((std::string)"SchrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ref) : Form(ref.getName(), ref.getGradeSigned(), ref.getGradeExecuted())
{
	this->_target = ref.getTarget();
	this->setBool(ref.getBool());
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	this->setBool(rhs.getBool());
	this->_target = rhs.getTarget();
	return (*this);
}

std::string				ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

const char				*ShrubberyCreationForm::fileException::what() const throw()
{
	return ("File could not be created");
}

void					ShrubberyCreationForm::proceedAction(void) const
{
	std::string			tree;
	std::string			filename = this->getTarget() + "_shrubbery";
	std::ofstream		file(filename.c_str());

	if (file.fail())
		throw ShrubberyCreationForm::fileException();
	tree = 
			"               ,@@@@@@@,\n"
			"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
			"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
			"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
			"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
			"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
			"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
			"       |o|        | |         | |\n"
			"       |.|        | |         | |\n"
			"\\_\\\\\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n"
		;
	file << tree;
	file.close();
}
