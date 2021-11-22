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

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <iostream>
# include <stdlib.h>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{

	public:

		NinjaTrap();
		NinjaTrap(std::string name);
		NinjaTrap(NinjaTrap const &ref);
		~NinjaTrap();

		NinjaTrap	&operator=(NinjaTrap const &rhs);

		void		ninjaShoebox(ClapTrap const &clap);
		void		ninjaShoebox(FragTrap const &frag);
		void		ninjaShoebox(ScavTrap const &scav);
		void		ninjaShoebox(NinjaTrap const &ninja);
};

#endif
