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

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{

	public:

		typedef typename std::stack<T>::container_type::iterator	iterator;

		MutantStack(void) : std::stack<T>() 
		{
		}

		MutantStack( MutantStack<T> const &ref) : std::stack<T>(ref)
		{
		}

		~MutantStack(void)
		{
		}

		MutantStack<T>		&operator=(MutantStack<T> const &rhs)
		{
			this->c = rhs.c;
			return (*this);
		};

		iterator			begin(void)
		{
			return (this->c.begin());
		};

		iterator			end(void)
		{
			return (this->c.end());
		};
};

#endif
