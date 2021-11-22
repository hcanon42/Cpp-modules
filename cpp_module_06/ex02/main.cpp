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

#include "Classes.hpp"
#include "Base.hpp"

void	identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "\"A\" (from pointer identification)" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "\"B\" (from pointer identification)" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "\"C\" (from pointer identification)" << std::endl;
}

void	identify_from_reference(Base &p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "\"A\" (from reference identification)" << std::endl;
	}
	catch(std::exception& e)
	{
	}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "\"B\" (from reference identification)" << std::endl;
	}
	catch(std::exception& e)
	{
	}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "\"C\" (from reference identification)" << std::endl;
	}
	catch(std::exception& e)
	{
	}
}

int		main()
{
	Base	*a = new A();
	Base	*b = new B();
	Base	*c = new C();

	identify_from_pointer(a);
	identify_from_pointer(b);
	identify_from_pointer(c);
	std::cout << std::endl;
	identify_from_reference(*a);
	identify_from_reference(*b);
	identify_from_reference(*c);

	delete a;
	delete b;
	delete c;
	return (0);
}
