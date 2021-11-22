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

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"
# include <string>

class PlasmaRifle : public AWeapon
{

	public:

		PlasmaRifle();
		PlasmaRifle(PlasmaRifle const &ref);
		virtual ~PlasmaRifle();

		PlasmaRifle		&operator=(PlasmaRifle const &rhs);

		void 			attack() const;
};

#endif
