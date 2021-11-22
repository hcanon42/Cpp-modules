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

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

class Awesome
{
	private:
		int		_n;
	public:
		Awesome(int n) : _n(n) {}
		Awesome() : _n(0) {}
		bool			operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
		bool			operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
		bool			operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
		bool			operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
		bool			operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
		bool			operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
		Awesome const	&operator=(Awesome const &rhs) { this->_n = rhs.getInt(); return (*this); }
		int				getInt() const { return (this->_n); }
};

std::ostream	&operator<<(std::ostream &o, Awesome const &ref)
{
	std::cout << ref.getInt();
	return (o);
}

template<typename T>
T const		&max(T const &x, T const &y)
{
	if (x > y)
		return (x);
	return (y);
}

template<typename T>
T const		&min(T const &x, T const &y)
{
	if (x < y)
		return (x);
	return (y);
}

template<typename T>
void		swap(T &x, T &y)
{
	T	tmp;

	tmp = y;
	y = x;
	x = tmp;
}

#endif
