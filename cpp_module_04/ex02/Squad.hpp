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

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"
# include <stdlib.h>

class Units
{

	private:

		Units			*_next;
		ISpaceMarine	*_unit;

	public:

		Units(ISpaceMarine* unit = NULL);
		Units(const Units& other);
		virtual ~Units();

		Units			&operator=(const Units& other);
		Units			*getNext() const;
		ISpaceMarine	*getUnit() const;
		void			setNext(Units* next);
		void			setUnit(ISpaceMarine* unit);
};

class Squad : public ISquad
{

	private:

		Units			*_units;
		int				_count;

	public:

		Squad();
		Squad(const Squad& other);
		virtual ~Squad();

		Squad& operator=(const Squad& other);

		int				getCount() const;
		ISpaceMarine	*getUnit(int n) const;
		int				push(ISpaceMarine* unit);
};

#endif
