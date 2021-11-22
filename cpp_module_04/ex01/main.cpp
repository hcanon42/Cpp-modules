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

#include "Character.hpp"
#include "Enemy.hpp"
#include "AWeapon.hpp"
#include "RadScorpion.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "PlasmaRifle.hpp"
#include <iostream>

int main()
{
	std::cout << "\n--- CONSTRUCTORS WEAPONS ---" << std::endl << std::endl;
	PlasmaRifle	pr_def;
	PlasmaRifle	pr_cpy(pr_def);
	PlasmaRifle	pr_assign;
	pr_assign = pr_cpy;

	PowerFist	pf_def;
	PowerFist	pf_cpy(pf_def);
	PowerFist	pf_assign;
	pf_assign = pf_cpy;

	std::cout << pr_def.getName() << ' ' <<  pr_def.getDamage() << ' ' <<  pr_def.getAPCost() << std::endl;
	std::cout << pr_cpy.getName() << ' ' <<  pr_cpy.getDamage() << ' ' <<  pr_cpy.getAPCost() << std::endl;
	std::cout << pr_assign.getName() << ' ' <<  pr_assign.getDamage() << ' ' <<  pr_assign.getAPCost() << '\n' << std::endl << std::endl;

	std::cout << pf_def.getName() << ' ' <<  pf_def.getDamage() << ' ' <<  pf_def.getAPCost() << std::endl;
	std::cout << pf_cpy.getName() << ' ' <<  pf_cpy.getDamage() << ' ' <<  pf_cpy.getAPCost() << std::endl;
	std::cout << pf_assign.getName() << ' ' <<  pf_assign.getDamage() << ' ' <<  pf_assign.getAPCost() << std::endl << std::endl;

	std::cout << "\n---- ATTACK WEAPONS ----" << std::endl << std::endl;
	pr_def.attack();
	pf_def.attack();

	std::cout << "\n---- CONSTRUCTORS ENEMY ----" << std::endl << std::endl;
	Enemy e(50, "Gros ver pas beau");
	Enemy e_neghp(-20, "Test");
	Enemy e_cpy(e);
	Enemy e_assign(0, "TEMP");
	e_assign = e;

	std::cout << e.getHP() << ' ' << e.getType() << std::endl;
	std::cout << e_cpy.getHP() << ' ' << e_cpy.getType() << std::endl;
	std::cout << e_assign.getHP() << ' ' << e_assign.getType() << std::endl;
	std::cout << e_neghp.getHP() << ' ' << e_neghp.getType() << std::endl << std::endl;

	std::cout << "\n---- TAKE DAMAGE ENEMY ----" << std::endl << std::endl;
	e.takeDamage(e.getHP() / 2);
	std::cout << e.getHP() << std::endl;
	e.takeDamage(e.getHP() / 2);
	std::cout << e.getHP() << std::endl;
	e.takeDamage(e.getHP() + 50);
	std::cout << e.getHP() << std::endl << std::endl;

	std::cout << "\n---- CONSTRUCTORS INHERITED ENEMIES ----" << std::endl << std::endl;
	SuperMutant* sm_def = new SuperMutant();
	SuperMutant* sm_cpy = new SuperMutant(*sm_def);
	SuperMutant* sm_assign = new SuperMutant();
	*sm_assign = *sm_def;

	RadScorpion* rs_def = new RadScorpion();
	RadScorpion* rs_cpy = new RadScorpion(*rs_def);
	RadScorpion* rs_assign = new RadScorpion();
	*rs_assign = *rs_def;

	std::cout << sm_def->getHP() << ' ' << sm_def->getType() << std::endl;
	std::cout << sm_cpy->getHP() << ' ' << sm_cpy->getType() << std::endl;
	std::cout << sm_assign->getHP() << ' ' << sm_assign->getType() << std::endl << std::endl;

	std::cout << rs_def->getHP() << ' ' << rs_def->getType() << std::endl;
	std::cout << rs_cpy->getHP() << ' ' << rs_cpy->getType() << std::endl;
	std::cout << rs_assign->getHP() << ' ' << rs_assign->getType() << std::endl << std::endl;

	std::cout << "\n---- TAKE DAMAGE INHERITED ENEMIES ----" << std::endl << std::endl;
	sm_def->takeDamage(5);
	std::cout << sm_def->getHP() << std::endl;
	sm_def->takeDamage(sm_def->getHP() / 2);
	std::cout << sm_def->getHP() << std::endl;
	sm_def->takeDamage(sm_def->getHP() + 50);
	std::cout << sm_def->getHP() << std::endl;

	rs_def->takeDamage(5);
	std::cout << rs_def->getHP() << std::endl;
	rs_def->takeDamage(rs_def->getHP() / 2);
	std::cout << rs_def->getHP() << std::endl;
	rs_def->takeDamage(rs_def->getHP() + 50);
	std::cout << rs_def->getHP() << std::endl << std::endl;

	std::cout << "\n---- CONSTRUCTORS CHARACTER ----" << std::endl << std::endl;
	Character c("Gros bg");
	Character c_cpy(c);
	Character c_assign("TEMP");
	c_assign = c;

	std::cout << c << c_cpy << c_assign << std::endl;

	std::cout << "\n---- EQUIP ----" << std::endl << std::endl;
	c.equip(&pr_def);
	std::cout << &pr_def << ' ' << c.getWeapon() << '\n' << c;
	c.equip(&pf_def);
	std::cout << &pf_def << ' ' << c.getWeapon() << '\n' << c;
	c.equip(NULL);
	std::cout << c.getWeapon() << '\n' << c << std::endl;

	std::cout << "\n---- ATTACK ----" << std::endl << std::endl;
	c.attack(sm_cpy); // NE FAIT RIEN
	c.attack(rs_cpy); // NE FAIT RIEN
	c.attack(NULL); // NE FAIT RIEN
	c.equip(&pf_def);
	c.attack(NULL); // NE FAIT RIEN

	std::cout << rs_cpy->getHP() << std::endl;
	c.attack(rs_cpy);
	std::cout << rs_cpy->getHP() << std::endl;
	c.attack(rs_cpy); // TUE L'ENNEMI

	std::cout << sm_cpy->getHP() << std::endl;
	c.attack(sm_cpy);
	std::cout << sm_cpy->getHP() << std::endl;
	c.attack(sm_cpy);
	std::cout << c;
	c.attack(sm_cpy);
	std::cout << c;
	c.attack(sm_cpy); // NE FAIT RIEN (plus d'ap)
	std::cout << c << std::endl;
	c_cpy.equip(&pr_def);
	c_cpy.attack(sm_cpy);
	c_cpy.attack(sm_cpy); // TUE L'ENNEMI

	std::cout << "\n---- RECOVER AP ----" << std::endl << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << c;
		c.recoverAP();
	}

	std::cout << "\n---- BASE DESTRUCTORS ----" << std::endl << std::endl;
	Enemy* base_sm = new SuperMutant();
	Enemy* base_rs = new RadScorpion();
	AWeapon* base_pf = new PowerFist();
	AWeapon* base_pr = new PlasmaRifle();

	delete base_sm;
	delete base_rs;
	delete base_pf;
	delete base_pr;

	std::cout << "\n---- DESTRUCTORS ----" << std::endl << std::endl;
	delete sm_assign;
	delete rs_assign;
	delete sm_def;
	delete rs_def;
	return 0;
}
