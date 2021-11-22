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

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{

	private:

		std::string		_knownForms[3];
		Form			*(*_knownConstructor[3])(std::string target);

	public:

		Intern();
		Intern(Intern const &ref);
		~Intern();

		Intern		&operator=(Intern const &rhs);

		Form		*makeForm(std::string name, std::string target);
	
		class		UnknownFormException : public std::exception
		{
			public:
				UnknownFormException() {}
				UnknownFormException(UnknownFormException const &ref) { (void)ref; }
				UnknownFormException	&operator=(UnknownFormException const &rhs) { (void)rhs; return (*this); }
				virtual const char *what() const throw();
		};
};

#endif
