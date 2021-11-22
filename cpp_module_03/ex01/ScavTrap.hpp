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

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <stdlib.h>

class ScavTrap
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

		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &ref);
		~ScavTrap();

		ScavTrap	&operator=(ScavTrap const &rhs);

		void		rangedAttack(std::string const &target) const;
		void		meleeAttack(std::string const &target) const;
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		challengeNewcomer();
		int			getEnergy() const;
		int			getHP() const;
};

#endif
