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

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>

class Enemy
{

	private:
		
		int 			_hp;
		std::string		_type;
		Enemy();

	public:
		
		Enemy(int hp, std::string type);
		Enemy(Enemy const &ref);
		virtual ~Enemy();

		Enemy	&operator=(Enemy const &rhs);

		std::string 	getType() const;
		int 			getHP() const;
		void			setHP(int hp);
		virtual void	takeDamage(int amount);
};

#endif
