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

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class ICharacter;

#include <string>
#include "ICharacter.hpp"

class AMateria
{

	private:

		unsigned int		_xp;
		std::string			_type;
		AMateria();

	public:

		AMateria(std::string const &type);
		AMateria(AMateria const &ref);
		virtual ~AMateria();

		AMateria			&operator=(AMateria const &rhs);

		std::string const	&getType() const;
		void				setXP(unsigned int xp);
		unsigned int		getXP() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};

#endif
