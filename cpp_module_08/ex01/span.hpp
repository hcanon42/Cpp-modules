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

#ifndef SPAN_HPP
# define SPAN_HPP

# include <limits.h>
# include <vector>
# include <algorithm>
# include <iostream>
# include <stdlib.h>

class span
{

	private:

		unsigned int		_n;
		std::vector<int>	_lst;
		span();

	public:

		span(unsigned int n);
		span(span const &ref);
		~span();

		span				&operator=(span const &rhs);

		void				addNumber(int n);
		void				addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int					shortestSpan(void);
		int					longestSpan(void);
		std::vector<int>	getList(void) const;
};

#endif
