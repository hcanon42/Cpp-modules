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

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include <iostream>

int main()
{
	std::cout << "---- CONSTRUCTORS SORCERER ----" << std::endl;
	Sorcerer sor("Robert", "the Magnificent");
	Sorcerer sor_cpy(sor);
	Sorcerer sor_assign("Temp", "the Temporary");
	sor_assign = sor;
	std::cout << sor_assign;

	std::cout << "\n---- CONSTRUCTORS VICTIM ----" << std::endl;
	Victim vic("Jimmy");
	Victim vic_cpy(vic);
	Victim vic_assign("Temp");
	vic_assign = vic;
	std::cout << vic_assign;

	std::cout << "\n---- CONSTRUCTORS PEON ----" << std::endl;
	Peon peon("Thrall");
	Peon peon_cpy(peon);
	Peon peon_assign("Temp");
	peon_assign = peon;
	std::cout << peon_assign;

	std::cout << "\n---- operator<< ----" << std::endl;
	std::cout << sor << sor_cpy << sor_assign << std::endl;
	std::cout << vic << vic_cpy << vic_assign << std::endl;
	std::cout << peon << peon_cpy << peon_assign;

	std::cout << "\n---- GET POLYMORPHED ----" << std::endl;
	vic.getPolymorphed();
	peon.getPolymorphed();

	std::cout << "\n---- POLYMORPH ----" << std::endl;
	sor.polymorph(vic);
	sor.polymorph(peon);

	std::cout << "\n---- BASE DESTRUCTORS ----" << std::endl;
	Victim	*base_peon = new Peon("Test");
	delete base_peon;

	std::cout << "\n---- DESTRUCTORS ----" << std::endl;
	return (0);
}
