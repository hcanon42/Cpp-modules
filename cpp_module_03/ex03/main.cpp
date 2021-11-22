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

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int		main()
{
	std::cout << std::endl << "--------------------------constructors--------------------------" << std::endl << std::endl;
	FragTrap	a("KILLER-v1.0");
	FragTrap	b(a);
	std::cout << std::endl;

	ScavTrap	c("PORTER-v1.0");
	ScavTrap	d(c);
	std::cout << std::endl;

	NinjaTrap	e("NINJA-v1.0");
	NinjaTrap	f(e);
	std::cout << std::endl << "--------------------------ranged && melee attacks--------------------------" << std::endl << std::endl;
	a.rangedAttack("Sir Hammerlock");
	a.meleeAttack("Handsome Jack");
	std::cout << std::endl;

	c.rangedAttack("Sir Hammerlock");
	c.meleeAttack("Handsome Jack");
	std::cout << std::endl;

	e.rangedAttack("Sir Hammerlock");
	e.meleeAttack("Handsome Jack");
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
	std::cout << "Fragtrap has " << b.getHP() << "HP left." << std::endl << std::endl;

	d.takeDamage(20);
	std::cout << "Scavtrap has " << d.getHP() << "HP left." << std::endl;
	d.takeDamage(20);
	std::cout << "Scavtrap has " << d.getHP() << "HP left." << std::endl;
	d.takeDamage(20);
	std::cout << "Scavtrap has " << d.getHP() << "HP left." << std::endl;
	d.takeDamage(20);
	std::cout << "Scavtrap has " << d.getHP() << "HP left." << std::endl;
	d.takeDamage(20);
	std::cout << "Scavtrap has " << d.getHP() << "HP left." << std::endl;
	d.takeDamage(20);
	std::cout << "Scavtrap has " << d.getHP() << "HP left." << std::endl;
	d.takeDamage(20);
	std::cout << "Scavtrap has " << d.getHP() << "HP left." << std::endl << std::endl;

	f.takeDamage(20);
	std::cout << "NinjaTrap has " << f.getHP() << "HP left." << std::endl;
	f.takeDamage(20);
	std::cout << "NinjaTrap has " << f.getHP() << "HP left." << std::endl;
	f.takeDamage(20);
	std::cout << "NinjaTrap has " << f.getHP() << "HP left." << std::endl;
	f.takeDamage(20);
	std::cout << "NinjaTrap has " << f.getHP() << "HP left." << std::endl;
	f.takeDamage(20);
	std::cout << "NinjaTrap has " << f.getHP() << "HP left." << std::endl;
	std::cout << std::endl << "--------------------------Repairing damage--------------------------" << std::endl << std::endl;
	b.beRepaired(45);
	std::cout << "Fragtrap has " << b.getHP() << "HP left." << std::endl;
	b.beRepaired(45);
	std::cout << "Fragtrap has " << b.getHP() << "HP left." << std::endl;
	b.beRepaired(45);
	std::cout << "Fragtrap has " << b.getHP() << "HP left." << std::endl << std::endl;

	d.beRepaired(45);
	std::cout << "Scavtrap has " << d.getHP() << "HP left." << std::endl;
	d.beRepaired(45);
	std::cout << "Scavtrap has " << d.getHP() << "HP left." << std::endl;
	d.beRepaired(45);
	std::cout << "Scavtrap has " << d.getHP() << "HP left." << std::endl << std::endl;

	f.beRepaired(45);
	std::cout << "NinjaTrap has " << f.getHP() << "HP left." << std::endl;
	f.beRepaired(45);
	std::cout << "NinjaTrap has " << f.getHP() << "HP left." << std::endl;
	f.beRepaired(45);
	std::cout << "NinjaTrap has " << f.getHP() << "HP left." << std::endl;
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
	std::cout << "Fragtrap has " << a.getEnergy() << " energy left." << std::endl << std::endl;

	c.challengeNewcomer();
	std::cout << "Scavtrap has " << c.getEnergy() << " energy left." << std::endl;
	c.challengeNewcomer();
	std::cout << "Scavtrap has " << c.getEnergy() << " energy left." << std::endl;
	c.challengeNewcomer();
	std::cout << "Scavtrap has " << c.getEnergy() << " energy left." << std::endl;
	c.challengeNewcomer();
	std::cout << "Scavtrap has " << c.getEnergy() << " energy left." << std::endl;
	c.challengeNewcomer();
	std::cout << "Scavtrap has " << c.getEnergy() << " energy left." << std::endl << std::endl;
	
	e.ninjaShoebox(a);
	std::cout << "NinjaTrap has " << e.getEnergy() << " energy left." << std::endl;
	e.ninjaShoebox(c);
	std::cout << "NinjaTrap has " << e.getEnergy() << " energy left." << std::endl;
	e.ninjaShoebox(e);
	std::cout << "NinjaTrap has " << e.getEnergy() << " energy left." << std::endl;
	e.ninjaShoebox(ClapTrap(100, 100, 100, 100, 1, "Clappy", 12, 5, 5, "CL4P-TR"));
	std::cout << "NinjaTrap has " << e.getEnergy() << " energy left." << std::endl;
	e.ninjaShoebox(a);
	std::cout << "NinjaTrap has " << e.getEnergy() << " energy left." << std::endl;
	std::cout << std::endl << "--------------------------destructors--------------------------" << std::endl << std::endl;
}