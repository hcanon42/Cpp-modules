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

#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include <iostream>

int main()
{
	std::cout << "---- CONSTRUCTORS MARINES ----" << std::endl << std::endl;
	TacticalMarine tm_def;
	TacticalMarine tm_cpy(tm_def);
	TacticalMarine tm_assign;
	tm_assign = tm_def;
	ISpaceMarine* tm_clone = tm_def.clone();

	AssaultTerminator at_def;
	AssaultTerminator at_cpy;
	AssaultTerminator at_assign;
	at_assign = at_def;
	ISpaceMarine* at_clone = at_def.clone();

	std::cout << "\n---- BATTLE CRY ----" << std::endl << std::endl;
	tm_def.battleCry();
	tm_cpy.battleCry();
	tm_assign.battleCry();
	tm_clone->battleCry();

	at_def.battleCry();
	at_cpy.battleCry();
	at_assign.battleCry();
	at_clone->battleCry();

	std::cout << "\n---- ATTACKS ----" << std::endl << std::endl;
	tm_def.rangedAttack();
	tm_cpy.rangedAttack();
	tm_assign.rangedAttack();
	tm_clone->rangedAttack();
	at_def.rangedAttack();
	at_cpy.rangedAttack();
	at_assign.rangedAttack();
	at_clone->rangedAttack();

	tm_def.meleeAttack();
	tm_cpy.meleeAttack();
	tm_assign.meleeAttack();
	tm_clone->meleeAttack();
	at_def.meleeAttack();
	at_cpy.meleeAttack();
	at_assign.meleeAttack();
	at_clone->meleeAttack();

	std::cout << "\n---- CONSTRUCTORS SQUAD ----" << std::endl << std::endl;
	Squad* sq_def = new Squad();
	Squad* sq_cpy = new Squad(*sq_def);
	Squad* sq_assign = new Squad();
	*sq_assign = *sq_def;

	std::cout << "There is actually " << sq_def->getCount() << " soldier in the 1st squad.\nTrying to get first (inexistant) unit from 1st squad... ---> " << (sq_def->getUnit(0) == 0 ? "FAILURE" : "SUCCESS") << std::endl;
	std::cout << std::endl << "There is actually " << sq_cpy->getCount() << " soldier in the 2nd squad.\nTrying to get first (inexistant) unit from 2nd squad... ---> " << (sq_cpy->getUnit(0) == 0 ? "FAILURE" : "SUCCESS") << std::endl;
	std::cout << std::endl << "There is actually " << sq_assign->getCount() << " soldier in the 3rd squad.\nTrying to get first (inexistant) unit from 3rd squad... ---> " << (sq_assign->getUnit(0) == 0 ? "FAILURE" : "SUCCESS") << std::endl;

	std::cout << "\n---- PUSH ----" << std::endl << std::endl;
	
	std::cout << "Pushing 20 soldiers in the squad..." << std::endl << std::endl;
	for (int i = 0; i < 20; i++)
		sq_def->push(rand() % 2 ? (ISpaceMarine*)new TacticalMarine() : (ISpaceMarine*)new AssaultTerminator());
	std::cout << std::endl << "There are " << sq_def->getCount() << " soldiers in the squad." << std::endl << std::endl;

	std::cout << std::endl << "Trying to add a NULL soldier to the squad... ---> " << (sq_def->push(NULL) == 1 ? "SUCCESS" : "FAILURE") << std::endl;
	std::cout << "There are " << sq_def->getCount() << " soldiers in the squad." << std::endl;

	std::cout << std::endl << "Trying to add a normal soldier to the squad... ---> " << (sq_def->push(at_clone) == 1 ? "SUCCESS" : "FAILURE") << std::endl;
	std::cout << "There are " << sq_def->getCount() << " soldiers in the squad." << std::endl;

	std::cout << std::endl << "Trying to add the same soldier to the squad... ---> " << (sq_def->push(at_clone) == 1 ? "SUCCESS" : "FAILURE") << std::endl;
	std::cout << "There are " << sq_def->getCount() << " soldiers in the squad." << std::endl;


	std::cout << "\n---- GET UNIT ----" << std::endl << std::endl;

	std::cout << "Trying to get unit from squad[-5] to squad[length + 5]..." << std::endl << std::endl;
	for (int i = -5; i < sq_def->getCount() + 5; i++)
	{
		if (sq_def->getUnit(i))
			sq_def->getUnit(i)->meleeAttack();
		else
			std::cout << i << std::endl;
	}

	std::cout << "\n---- DEEP COPY ----" << std::endl << std::endl;

	delete sq_cpy;

	std::cout << "Copying to an empty squad..." << std::endl << std::endl;
	sq_cpy = new Squad(*sq_def);
	std::cout << std::endl << "There are " << sq_cpy->getCount() << " soldiers in the copied squad." << std::endl << std::endl;

	std::cout << "Copying to a non-empty squad..." << std::endl << std::endl;
	sq_assign->push(new TacticalMarine());
	sq_assign->push(new AssaultTerminator());
	std::cout << std::endl << "There are " << sq_assign->getCount() << " soldiers in the squad." << std::endl << std::endl;
	std::cout << "Launching copy..." << std::endl << std::endl;
	*sq_assign = *sq_def;
	std::cout << std::endl << "There are " << sq_assign->getCount() << " soldiers in the copied squad." << std::endl << std::endl;

	std::cout << "\n---- BASE DESTRUCTORS ----" << std::endl << std::endl;

	ISpaceMarine* base_at = new AssaultTerminator();
	ISpaceMarine* base_tm = new TacticalMarine();
	ISquad* base_sq = new Squad();

	delete base_at;
	delete base_tm;
	delete base_sq;

	std::cout << "\n---- DESTRUCTORS ----" << std::endl << std::endl;

	delete sq_def;
	delete sq_cpy;
	delete sq_assign;
	delete tm_clone;
}
