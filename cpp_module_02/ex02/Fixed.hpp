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

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{

	private:

		int 				_value;
		int const static	_bits = 8;

	public:

		Fixed(void);
		Fixed(int const i);
		Fixed(float const f);
		Fixed(Fixed const & src);
		~Fixed();

		Fixed		&operator=(Fixed const &rhs);
		Fixed		operator*(Fixed const &rhs) const;
		Fixed		operator/(Fixed const &rhs) const;
		Fixed		operator-(Fixed const &rhs) const;
		Fixed		operator+(Fixed const &rhs) const;
		Fixed const	operator++(int);
		Fixed		&operator++();
		Fixed const	operator--(int);
		Fixed		&operator--();
		int			operator==(Fixed const &rhs) const;
		int			operator>=(Fixed const &rhs) const;
		int			operator<=(Fixed const &rhs) const;
		int			operator!=(Fixed const &rhs) const;
		int			operator>(Fixed const &rhs) const;
		int			operator<(Fixed const &rhs) const;

		int						getRawBits(void) const;
		void					setRawBits(int value);
		float					toFloat(void) const;
		int						toInt(void) const;
		const static Fixed		&min(Fixed const &ref1, Fixed const &ref2);
		const static Fixed		&max(Fixed const &ref1, Fixed const &ref2);
};

std::ostream					&operator<<(std::ostream &out, const Fixed &val);

#endif
