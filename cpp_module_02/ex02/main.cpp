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
#include "Fixed.hpp"

int		main()
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed const c(Fixed(5.05f) + Fixed(2));
	Fixed const d(Fixed(5.05f) - Fixed(2));
	Fixed const e(Fixed(5.05f) / Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << "b --> " << b << std::endl;
	std::cout << "c --> " << c << std::endl;
	std::cout << "d --> " << d << std::endl;
	std::cout << "e --> " << e << std::endl;

	std::cout << "(b > c)  --> " << (b > c) << std::endl;
	std::cout << "(c == d) --> " << (c == d) << std::endl;
	std::cout << "(d < e)  --> " << (d < e) << std::endl;
	std::cout << "(e == e) --> " << (e == e) << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;

	return (0);
}
