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

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
	private:
		std::string 	_name;
		int 			_apPoints;
		AWeapon 		*_weapon;
		Character();

	public:
		Character(std::string name);
		Character(Character const & ref);
		virtual ~Character();

		Character&		operator=(Character const &rhs);

		void 			recoverAP();
		void 			equip(AWeapon* weapon);
		void 			attack(Enemy* enemy);
		std::string 	getName() const;
		int 			getAPPoints() const;
		AWeapon 		*getWeapon() const;
};

std::ostream 			&operator<<(std::ostream &os, Character const &c);

#endif
