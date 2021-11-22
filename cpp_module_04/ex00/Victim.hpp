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

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim
{

	private:

		std::string		_name;

	public:

		Victim(std::string name);
		Victim(Victim const &ref);
		virtual ~Victim();

		Victim	&operator=(Victim const &rhs);

		std::string		getName() const;
		void			setName(std::string name);
		virtual void	getPolymorphed() const;
};

std::ostream	&operator<<(std::ostream &o, Victim const &victim);

#endif