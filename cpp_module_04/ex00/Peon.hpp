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

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"
# include <iostream>

class Peon : public Victim
{

	public:

		Peon(std::string name);
		Peon(Peon const &ref);
		virtual ~Peon();

		Peon	&operator=(Peon const &rhs);

		void	getPolymorphed() const;
};

std::ostream	&operator<<(std::ostream &o, Peon const &peon);

#endif