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

#include "span.hpp"

int		main()
{
	span	array(11000);

	std::cout << "-------------------------BASIC TEST--------------------------" << std::endl << std::endl;
	array.addNumber(5);
	array.addNumber(3);
	array.addNumber(17);
	array.addNumber(9);
	array.addNumber(11);
	std::cout << array.shortestSpan() << std::endl;
	std::cout << array.longestSpan() << std::endl;

	std::cout << std::endl << "-------------------------OTHER TESTS--------------------------" << std::endl << std::endl;
	array.addNumber(array.getList().begin(), array.getList().begin() + 10000);
	std::cout << "Just added TEN THOUSANDS RANDOM NUMBERS !" << std::endl;
	std::cout << array.shortestSpan() << std::endl;
	std::cout << array.longestSpan() << std::endl;

	try
	{
		array.addNumber(12);
		std::cout << std::endl << "Trying to overflow the vector..." << std::endl;
		array.addNumber(array.getList().begin(), array.getList().begin() + 1000);
		std::cout << "This worked... It is not supposed to !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed successfully : " << e.what() << std::endl;
	}
	return (0);
}