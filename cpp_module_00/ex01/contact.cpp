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

#include "contact.hpp"

contact::contact(void)
{
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_birthday_date = "";
	this->_darkest_secret = "";
	this->_email_address = "";
	this->_phone_number = "";
	this->_postal_address = "";
	this->_login = "";
	this->_underwear_color = "";
	this->_favorite_meal = "";
}

std::string		contact::getFirstName() const
{
	return (this->_first_name);
}

void			contact::setFirstName(std::string str)
{
	this->_first_name = str;
}

std::string		contact::getLastName() const
{
	return (this->_last_name);
}

void			contact::setLastName(std::string str)
{
	this->_last_name = str;
}

std::string			contact::getNickname() const
{
	return (this->_nickname);
}

void				contact::setNickname(std::string str)
{
	this->_nickname = str;
}

std::string			contact::getLogin() const
{
	return (this->_login);
}
	
void				contact::setLogin(std::string str)
{
	this->_login = str;
}

std::string			contact::getPostalAddress() const
{
	return (this->_postal_address);
}

void				contact::setPostalAddress(std::string str)
{
	this->_postal_address = str;
}

std::string			contact::getEmailAddress() const
{
	return (this->_email_address);
}

void				contact::setEmailAddress(std::string str)
{
	this->_email_address = str;
}

std::string			contact::getPhoneNumber() const
{
	return (this->_phone_number);
}

void				contact::setPhoneNumber(std::string str)
{
	this->_phone_number = str;
}

std::string			contact::getBirthday() const
{
	return (this->_birthday_date);
}

void		contact::setBirthday(std::string str)
{
	this->_birthday_date = str;
}

std::string		contact::getFavoriteMeal() const
{
	return (this->_favorite_meal);
}

void				contact::setFavoriteMeal(std::string str)
{
	this->_favorite_meal = str;
}

std::string			contact::getUnderwearColor() const
{
	return (this->_underwear_color);
}

void				contact::setUnderwearColor(std::string str)
{
	this->_underwear_color = str;
}

std::string			contact::getDarkestSecret() const
{
	return (this->_darkest_secret);
}

void				contact::setDarkestSecret(std::string str)
{
	this->_darkest_secret = str;
}
