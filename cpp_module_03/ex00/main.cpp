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

#include "FragTrap.hpp"

int		main()
{
	std::cout << std::endl << "--------------------------constructors--------------------------" << std::endl << std::endl;
	FragTrap	a("KILLER-v1.0");
	FragTrap	b(a);

	std::cout << std::endl << "--------------------------ranged && melee attacks--------------------------" << std::endl << std::endl;
	a.rangedAttack("Sir Hammerlock");
	a.meleeAttack("Handsome Jack");
	std::cout << std::endl << "--------------------------taking damage--------------------------" << std::endl << std::endl;
	b.takeDamage(20);
	std::cout << "Fragtrap has " << b.getHP() << "HP left." << std::endl;
	b.takeDamage(20);
	std::cout << "Fragtrap has " << b.getHP() << "HP left." << std::endl;
	b.takeDamage(20);
	std::cout << "Fragtrap has " << b.getHP() << "HP left." << std::endl;
	b.takeDamage(20);
	std::cout << "Fragtrap has " << b.getHP() << "HP left." << std::endl;
	b.takeDamage(20);
	std::cout << "Fragtrap has " << b.getHP() << "HP left." << std::endl;
	b.takeDamage(20);
	std::cout << "Fragtrap has " << b.getHP() << "HP left." << std::endl;
	b.takeDamage(20);
	std::cout << "Fragtrap has " << b.getHP() << "HP left." << std::endl;
	b.takeDamage(100);
	std::cout << "Fragtrap has " << b.getHP() << "HP left." << std::endl;
	std::cout << std::endl << "--------------------------Repairing damage--------------------------" << std::endl << std::endl;
	b.beRepaired(45);
	std::cout << "Fragtrap has " << b.getHP() << "HP left." << std::endl;
	b.beRepaired(45);
	std::cout << "Fragtrap has " << b.getHP() << "HP left." << std::endl;
	b.beRepaired(45);
	std::cout << "Fragtrap has " << b.getHP() << "HP left." << std::endl;
	std::cout << std::endl << "--------------------------special attack && energy--------------------------" << std::endl << std::endl;
	a.vaulthunter_dot_exe("Sir Hammerlock");
	std::cout << "Fragtrap has " << a.getEnergy() << " energy left." << std::endl;
	a.vaulthunter_dot_exe("Sir Hammerlock");
	std::cout << "Fragtrap has " << a.getEnergy() << " energy left." << std::endl;
	a.vaulthunter_dot_exe("Sir Hammerlock");
	std::cout << "Fragtrap has " << a.getEnergy() << " energy left." << std::endl;
	a.vaulthunter_dot_exe("Sir Hammerlock");
	std::cout << "Fragtrap has " << a.getEnergy() << " energy left." << std::endl;
	a.vaulthunter_dot_exe("Sir Hammerlock");
	std::cout << "Fragtrap has " << a.getEnergy() << " energy left." << std::endl;
	a.vaulthunter_dot_exe("Sir Hammerlock");
	std::cout << "Fragtrap has " << a.getEnergy() << " energy left." << std::endl;
	a.vaulthunter_dot_exe("Sir Hammerlock");
	std::cout << "Fragtrap has " << a.getEnergy() << " energy left." << std::endl;
	std::cout << std::endl << "--------------------------destructors--------------------------" << std::endl << std::endl;
}