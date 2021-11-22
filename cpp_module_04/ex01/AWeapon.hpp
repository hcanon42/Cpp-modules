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

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <string>

class AWeapon
{

	private:

		AWeapon();
		std::string 	_name;
		int 			_apcost;
		int 			_damage;

	public:
		AWeapon(std::string name, int apcost, int damage);
		AWeapon(AWeapon const &ref);
		virtual ~AWeapon();

		AWeapon& 		operator=(AWeapon const &rhs);

		std::string 	getName() const;
		int 			getAPCost() const;
		int 			getDamage() const;
		virtual void 	attack() const = 0;
};

#endif
