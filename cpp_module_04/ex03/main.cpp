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

#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "---- CONSTRUCTORS ----" << std::endl;
	AMateria* ice_def = new Ice();
	AMateria* ice_cpy = new Ice(*((Ice*)ice_def));
	AMateria* ice_assign = new Ice();
	*ice_assign = *ice_def;

	AMateria* cure_def = new Cure();
	AMateria* cure_cpy = new Cure(*((Cure*)cure_def));
	AMateria* cure_assign = new Cure();
	*cure_assign = *cure_def;

	Character* char_def = new Character("Mimi Mathy");
	Character* char_cpy = new Character(*((Character*)char_def));
	Character* char_assign = new Character("TEMP");
	*char_assign = *char_def;

	std::cout << ice_def->getType() << " " << ice_def->getXP() << std::endl;
	std::cout << ice_cpy->getType() << " " << ice_cpy->getXP() << std::endl;
	std::cout << ice_assign->getType() << " " << ice_assign->getXP() << std::endl;

	std::cout << cure_def->getType() << " " << cure_def->getXP() << std::endl;
	std::cout << cure_cpy->getType() << " " << cure_cpy->getXP() << std::endl;
	std::cout << cure_assign->getType() << " " << cure_assign->getXP() << std::endl;

	std::cout << char_def->getName() << std::endl;
	std::cout << char_cpy->getName() << std::endl;
	std::cout << char_assign->getName() << std::endl;

	std::cout << "\n---- USE ----" << std::endl;
	ice_def->use(*char_def);
	std::cout << ice_def->getType() << " " << ice_def->getXP() << std::endl;
	ice_def->use(*char_def);
	std::cout << ice_def->getType() << " " << ice_def->getXP() << std::endl;
	cure_def->use(*char_def);
	std::cout << cure_def->getType() << " " << cure_def->getXP() << std::endl;
	cure_def->use(*char_def);
	std::cout << cure_def->getType() << " " << cure_def->getXP() << std::endl;

	std::cout << "\n---- CLONE ----" << std::endl;
	AMateria* ice_clone = ice_def->clone();
	AMateria* cure_clone = cure_def->clone();
	std::cout << ice_clone->getType() << " " << ice_clone->getXP() << std::endl;
	std::cout << cure_clone->getType() << " " << cure_clone->getXP() << std::endl;

	std::cout << "\n---- EQUIP/UNEQUIP ----" << std::endl;
	for (int i = -1; i < 6; i++)
		std::cout << "Inventory [" << i << "] = " << char_def->getMateria(i) << std::endl;
	std::cout << std::endl << "Equipping ice_def..." << std::endl;
	char_def->equip(ice_def);
	std::cout << char_def->getMateria(0) << " (equipped) == (original ice_def) " << ice_def << std::endl;
	std::cout << std::endl << "Equipping cure_def..." << std::endl;
	char_def->equip(cure_def);
	std::cout << char_def->getMateria(1) << " (equipped) == (original cure_def) " << cure_def << std::endl;
	std::cout << std::endl << "Equipping ice_cpy..." << std::endl;
	char_def->equip(ice_cpy);
	std::cout << char_def->getMateria(2) << " (equipped) == (original ice_cpy) " << ice_cpy << std::endl;
	std::cout << std::endl << "Equipping cure_cpy..." << std::endl;
	char_def->equip(cure_cpy);
	std::cout << char_def->getMateria(3) << " (equipped) == (original cure_cpy) " << cure_cpy << std::endl;
	std::cout << std::endl << "Equipping ice_assign while inventory is full..." << std::endl;
	char_def->equip(ice_assign); // NE FAIT RIEN
	std::cout << char_def->getMateria(3) << " (equipped) == (cure_cpy and not ice_assign) " << cure_cpy << std::endl;
	std::cout << std::endl << "Unequipping inventory[2] and equipping ice_assign..." << std::endl;
	char_def->unequip(2);
	char_def->equip(ice_assign);
	std::cout << char_def->getMateria(2) << " (equipped) == (original ice_assign) " << ice_assign << std::endl;
	std::cout << std::endl << "Unequipping inventory 2, 1, -5, 20 and printing inventory..." << std::endl;
	char_def->unequip(2);
	char_def->unequip(1);
	char_def->unequip(-5);
	char_def->unequip(20);
	for (int i = 0; i < 4; i++)
		std::cout << "Inventory [" << i << "] = " << char_def->getMateria(i) << std::endl;

	std::cout << "\n---- CHARACTER USE ----" << std::endl;
	Character tmp("Target");
	for (int i = 0; i < 4; i++)
		char_def->use(i, tmp);

	std::cout << "\n---- DEEP COPY ----" << std::endl;
	Character* char_cpy2 = new Character(*char_def);
	for (int i = 0; i < 4; i++)
		std::cout << char_cpy2->getMateria(i) << ' ' << char_def->getMateria(i) << std::endl;
	*char_cpy2 = *char_def;
	for (int i = 0; i < 4; i++)
		std::cout << char_cpy2->getMateria(i) << ' ' << char_def->getMateria(i) << std::endl;
	delete char_cpy2;

	std::cout << "\n---- CONSTRUCTORS MATERIASOURCE ----" << std::endl;
	MateriaSource ms_def;
	MateriaSource ms_cpy = MateriaSource(ms_def);
	MateriaSource ms_assign;
	ms_assign = ms_def;

	for (int i = 0; i < 4; i++)
		std::cout << ms_def.getMateria(i) << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << ms_assign.getMateria(i) << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << ms_cpy.getMateria(i) << std::endl;

	std::cout << "\n---- CREATE/LEARN MATERIA ----" << std::endl;
	ms_def.createMateria("ice"); // NE FAIT RIEN
	ms_def.learnMateria(ice_assign);
	ms_def.learnMateria(ms_def.getMateria(0));
	ms_def.learnMateria(cure_def);
	ms_def.learnMateria(ms_def.getMateria(2));
	ms_def.learnMateria(ms_def.getMateria(3)); // NE FAIT RIEN
	for (int i = 0; i < 4; i++)
		std::cout << ms_def.getMateria(i)->getType() << ' ' << ms_def.getMateria(i)->getXP() << std::endl;
	AMateria* ret = ms_def.createMateria("truc"); // NE FAIT RIEN
	std::cout << ret << ' ' << (ret ? ret->getType() : "") << std::endl;
	delete ret;
	ret = ms_def.createMateria("ice");
	std::cout << ret << ' ' << (ret ? ret->getType() : "") << std::endl;
	delete ret;
	ret = ms_def.createMateria("cure");
	std::cout << ret << ' ' << (ret ? ret->getType() : "") << std::endl;
	delete ret;

	std::cout << "\n---- BASE DESTRUCTORS ----" << std::endl;
	AMateria* base_ice = new Ice();
	AMateria* base_cure = new Cure();
	ICharacter* base_char = new Character("Test");
	IMateriaSource* base_src = new MateriaSource();

	delete base_ice;
	delete base_cure;
	delete base_char,
	delete base_src; // SI CA COMPILE C'EST BON

	std::cout << "\n---- DESTRUCTORS ----" << std::endl;
	delete ice_clone;
	delete cure_clone;
	delete cure_assign;
	delete ice_cpy;
	delete char_def;
	delete char_cpy;
	delete char_assign;
	return 0;
}
