/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcanon <hcanon@student.42.fr>              +#+  +:+       +#+        */
/*       A                                         +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:00:46 by hcanon            #+#    #+#             */
/*   Updated: 2020/11/12 12:12:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

# include <stdexcept>
# include <iostream>
# include <string>

class Bureaucrat;

class Form
{

	private:

		std::string	const	_name;
		bool				_signed;
		int	const			_minGradeToBeSigned;
		int	const			_minGradeToBeExecuted;
		Form();

	public:

		Form(std::string name, int gradeSigned, int gradeExecuted);
		Form(Form const &ref);
		virtual ~Form();

		Form		&operator=(Form const &rhs);

		std::string const		getName(void) const;
		bool					getBool(void) const;
		int						getGradeSigned(void) const;
		int						getGradeExecuted(void) const;
		void					setBool(bool sign);
		int						check_grade(int grade) const;
		void					getSigned(Bureaucrat const &bureaucrat);
		void					execute(Bureaucrat const &executor) const;
		virtual void			proceedAction(void) const = 0;

		class					GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException() {}
				GradeTooHighException(GradeTooHighException const &ref) {(void)ref;}
				GradeTooHighException	&operator=(GradeTooHighException const &rhs) { (void)rhs; return (*this); }
				virtual const char *what() const throw();
		};

		class					GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException() {}
				GradeTooLowException(GradeTooLowException const &ref) { (void)ref; }
				GradeTooLowException	&operator=(GradeTooLowException const &rhs) { (void)rhs; return (*this); }
				virtual const char *what() const throw();
		};

		class					FormNotSignedException : public std::exception
		{
			public:
				FormNotSignedException() {}
				FormNotSignedException(FormNotSignedException const &ref) { (void)ref; }
				FormNotSignedException	&operator=(FormNotSignedException const &rhs) { (void)rhs; return (*this); }
				virtual const char *what() const throw();
		};
};

std::ostream		&operator<<(std::ostream &out, Form const &form);

#endif
