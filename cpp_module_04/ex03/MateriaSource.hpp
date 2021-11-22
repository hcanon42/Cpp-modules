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

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

	private:

		AMateria		*_materias[4];

	public:

		MateriaSource();
		MateriaSource(MateriaSource const &ref);
		virtual ~MateriaSource();

		MateriaSource	&operator=(MateriaSource const &rhs);

		void			learnMateria(AMateria* m);
		AMateria		*createMateria(std::string const &type);
		AMateria		*getMateria(int i) const;
};

#endif
