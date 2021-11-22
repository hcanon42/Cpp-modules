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

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
}

Fixed::Fixed(int const i)
{
	this->setRawBits(i << this->_bits);
}

Fixed::Fixed(float const f)
{
	this->setRawBits(roundf(f * (1 << this->_bits)));
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::~Fixed()
{
}

Fixed 			&Fixed::operator=(Fixed const &rhs)
{
	this->setRawBits(rhs.getRawBits());
	return (*this);
}

int				Fixed::getRawBits(void) const
{
	return (this->_value);
}

void			Fixed::setRawBits(int value)
{
	this->_value = value;
}

float			Fixed::toFloat(void) const
{
	return ((float)(this->_value) / (1 << this->_bits));
}

int				Fixed::toInt(void) const
{
	return ((int)(this->_value >> this->_bits));
}

Fixed			Fixed::operator/(Fixed const &rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed			Fixed::operator-(Fixed const &rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed			Fixed::operator+(Fixed const &rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed			Fixed::operator*(Fixed const &rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed const		Fixed::operator++(int)
{
	Fixed const	cpy(*this);
	this->setRawBits(this->getRawBits() + 1);
	return (cpy);
}

Fixed			&Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed			&Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed const		Fixed::operator--(int)
{
	Fixed const	cpy(*this);
	this->setRawBits(this->getRawBits() - 1);
	return (cpy);
}

int				Fixed::operator==(Fixed const &rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (1);
	return (0);
}

int				Fixed::operator!=(Fixed const &rhs) const
{
	if (this->getRawBits() != rhs.getRawBits())
		return (1);
	return (0);
}

int				Fixed::operator>=(Fixed const &rhs) const
{
	if (this->getRawBits() >= rhs.getRawBits())
		return (1);
	return (0);
}

int				Fixed::operator<=(Fixed const &rhs) const
{
	if (this->getRawBits() <= rhs.getRawBits())
		return (1);
	return (0);
}

int				Fixed::operator>(Fixed const &rhs) const
{
	if (this->getRawBits() > rhs.getRawBits())
		return (1);
	return (0);
}

int				Fixed::operator<(Fixed const &rhs) const
{
	if (this->getRawBits() < rhs.getRawBits())
		return (1);
	return (0);
}

const Fixed		&Fixed::min(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 > ref2)
		return (ref2);
	return (ref1);
}

const Fixed		&Fixed::max(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 > ref2)
		return (ref1);
	return (ref2);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &val)
{
    out << val.toFloat();
    return (out);
}

