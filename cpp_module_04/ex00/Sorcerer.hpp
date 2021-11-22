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

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer
{

	private:

		std::string		_name;
		std::string		_type;

	public:

		Sorcerer(std::string name, std::string type);
		Sorcerer(Sorcerer const &ref);
		virtual ~Sorcerer();

		Sorcerer	&operator=(Sorcerer const &rhs);

		std::string		getName() const;
		void			setName(std::string name);
		std::string		getType() const;
		void			setType(std::string type);
		void			polymorph(Victim const &victim) const;
};

std::ostream	&operator<<(std::ostream &o, Sorcerer const &sorcerer);

#endif