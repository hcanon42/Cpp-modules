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

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <stdlib.h>

class FragTrap
{

	private:

		int					_maxHP;
		int					_HP;
		int 				_maxEnergy;
		int					_Energy;
		int					_level;
		std::string			_name;
		int 				_meleeDamage;
		int 				_distDamage;
		int 				_armor;

	public:

		FragTrap(std::string name);
		FragTrap(FragTrap const &ref);
		~FragTrap();

		FragTrap	&operator=(FragTrap const &rhs);

		void		rangedAttack(std::string const &target) const;
		void		meleeAttack(std::string const &target) const;
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		vaulthunter_dot_exe(std::string const &target);
		int			getEnergy();
		int			getHP();
};

#endif
