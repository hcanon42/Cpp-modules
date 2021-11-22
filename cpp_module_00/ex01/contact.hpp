/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcanon <hcanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:00:46 by hcanon            #+#    #+#             */
/*   Updated: 2020/11/05 13:45:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class contact {

	private:

	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_login;
	std::string	_postal_address;
	std::string	_email_address;
	std::string	_phone_number;
	std::string	_birthday_date;
	std::string	_favorite_meal;
	std::string	_underwear_color;
	std::string	_darkest_secret;

	public:

	std::string	getFirstName() const;
	void		setFirstName(std::string str);
	std::string	getLastName() const;
	void		setLastName(std::string str);
	std::string	getNickname() const;
	void		setNickname(std::string str);
	std::string	getLogin() const;
	void		setLogin(std::string str);
	std::string	getPostalAddress() const;
	void		setPostalAddress(std::string str);
	std::string	getEmailAddress() const;
	void		setEmailAddress(std::string str);
	std::string	getPhoneNumber() const;
	void		setPhoneNumber(std::string str);
	std::string	getBirthday() const;
	void		setBirthday(std::string str);
	std::string	getFavoriteMeal() const;
	void		setFavoriteMeal(std::string str);
	std::string	getUnderwearColor() const;
	void		setUnderwearColor(std::string str);
	std::string	getDarkestSecret() const;
	void		setDarkestSecret(std::string str);

	contact();
};

#endif
