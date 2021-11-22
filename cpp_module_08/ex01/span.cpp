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

span::span() : _n(0), _lst(0)
{
	srand(time(0));
}

span::span(unsigned int n) : _n(n), _lst(std::vector<int>())
{
	srand(time(0));
}

span::span(span const &ref)
{
	srand(time(0));
	*this = ref;
}

span::~span()
{
}

span			&span::operator=(span const &rhs)
{
	this->_lst = rhs._lst;
	this->_n = rhs._n;
	return (*this);
}

void			span::addNumber(int n)
{
	if (this->_lst.size() == this->_n)
		throw std::exception();
	this->_lst.push_back(n);
}

void			span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	int		i;

	i = -1;
	if (end - begin + this->_lst.size() > this->_n)
		throw std::exception();
	while (++i < end - begin)
		this->_lst.push_back(rand() % 10000000);
}

int					span::longestSpan()
{
	std::vector<int>::iterator	min;
	std::vector<int>::iterator	max;

	if (this->_lst.size() <= 1)
		throw std::exception();
	min = std::min_element(this->_lst.begin(), this->_lst.end());
	max = std::max_element(this->_lst.begin(), this->_lst.end());
	return ((*max - *min));
}

int					span::shortestSpan()
{
	std::vector<int>			cpy(this->_lst);
	int							i;
	int							min;

	min = INT_MAX;
	i = 0;
	if (this->_lst.size() <= 1)
		throw std::exception();
	std::sort(cpy.begin(), cpy.end());
	while (static_cast<std::vector<int>::size_type>(i) + 2 != cpy.size())
	{
		if (min > (cpy.at(i + 1) - cpy.at(i)))
			min = cpy.at(i + 1) - cpy.at(i);
		i++;
	}
	return (min);
}

std::vector<int>	span::getList(void) const
{
	return (this->_lst);
}
