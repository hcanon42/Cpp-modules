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


#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>
# include <cstring>
# include <iostream>

class ShrubberyCreationForm : public Form
{

	private:

		std::string				_target;
		ShrubberyCreationForm();

	public:

		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &ref);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

		virtual void			proceedAction(void) const;
		std::string				getTarget() const;

		class					fileException : public std::exception
		{
			public:
				fileException() {}
				fileException(fileException const &ref) { (void)ref; }
				fileException		&operator=(fileException const &rhs) { (void)rhs; return (*this); }
				virtual const char *what() const throw();
		};
};

#endif
