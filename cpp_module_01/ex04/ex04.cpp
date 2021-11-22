/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 14:46:52 by user42            #+#    #+#             */
/*   Updated: 2020/11/09 13:53:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(void)
{
	std::string	str;
	std::string	*pt_str;
	std::string	&ref_str = str;

	str = "HI THIS IS THE BRAIN";
	pt_str = &str;
	std::cout << std::endl << *pt_str << std::endl << ref_str << std::endl << std::endl;
	return (0);
}
