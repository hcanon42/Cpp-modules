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

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Form.hpp"

class Bureaucrat
{

	private:

		std::string	const	_name;
		int					_grade;
		Bureaucrat();

	public:

		Bureaucrat(int grade);
		Bureaucrat(Bureaucrat const &ref);
		~Bureaucrat();

		Bureaucrat		&operator=(Bureaucrat const &rhs);

		std::string		getName(void) const;
		int				getGrade(void) const;
		void			getPromoted(void);
		void			getDowngraded(void);
		void			signForm(Form &form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException() {}
				GradeTooHighException(GradeTooHighException const &ref) {(void)ref;}
				GradeTooHighException	&operator=(GradeTooHighException const &rhs) { (void)rhs; return (*this); }
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException() {}
				GradeTooLowException(GradeTooLowException const &ref) { (void)ref; }
				GradeTooLowException	&operator=(GradeTooLowException const &rhs) { (void)rhs; return (*this); }
				virtual const char *what() const throw();
		};
};

std::ostream		&operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
