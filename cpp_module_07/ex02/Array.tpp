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

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>
# include <string>

template<typename T>
class Array
{

	private:

		T				*_array;
		unsigned int	_n;

	public:

		Array<T>(void) : _array(NULL), _n(0) {}
		Array<T>(unsigned int n) : _array(new T[n]), _n(n) {}

		Array<T>(Array const &ref) : _array(NULL), _n(0)
		{
			this->_array = ref._array;
			this->_n = ref.size();
		}

		~Array<T>()
		{
			if (this->_array != NULL)
				delete[] this->_array;
		}

		Array			&operator=(Array const &rhs)
		{
			unsigned int	i;

			i = 0;
			if (this->_array != NULL)
				delete[] this->_array;
			this->_array = new T[rhs.size()];
			this->_n = rhs.size();
			while (i < rhs.size())
			{
				this->_array[i] = rhs._array[i];
				i++;
			}
			return (*this);
		}

		T				&operator[](unsigned int n) const
		{
			if (n >= this->size())
				throw std::exception();
			return (this->_array[n]);
		}

		unsigned int	size(void) const
		{
			if (this->_array == NULL)
				return (0);
			return (this->_n);
		}
};

#endif
