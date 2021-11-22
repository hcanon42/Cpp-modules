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

#ifndef CLASSES_HPP
# define CLASSES_HPP

# include "Base.hpp"

class A : public Base
{
	public:
		A() {}
		A(A const &ref) : Base() { (void)ref; }
		virtual ~A() {}
		A	&operator=(A const &rhs) { (void)rhs; return (*this); }
};

class B : public Base
{
	public:
		B() {}
		B(B const &ref) : Base() { (void)ref; }
		virtual ~B() {}
		B	&operator=(B const &rhs) { (void)rhs; return (*this); }
};

class C : public Base
{
	public:
		C() {}
		C(C const &ref) : Base() { (void)ref; }
		virtual ~C() {}
		C	&operator=(C const &rhs) { (void)rhs; return (*this); }
};

#endif
