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

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

	protected:

		int					_maxHP;
		int					_HP;
		int 				_maxEnergy;
		int					_Energy;
		int					_level;
		std::string			_name;
		int 				_meleeDamage;
		int 				_distDamage;
		int 				_armor;
		std::string			_type;

	public:

		ClapTrap();
		ClapTrap(int maxHP, int HP, int maxEnergy, int Energy, int lvl, std::string name, int meleeDamage, int distDamage, int armor, std::string type);
		ClapTrap(ClapTrap const &ref);
		~ClapTrap();

		ClapTrap	&operator=(ClapTrap const &rhs);

		void		rangedAttack(std::string const &target) const;
		void		meleeAttack(std::string const &target) const;
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		int			getEnergy() const;
		int			getHP() const;
};

#endif
