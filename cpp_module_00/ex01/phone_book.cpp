/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcanon <hcanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:00:46 by hcanon            #+#    #+#             */
/*   Updated: 2020/11/12 12:12:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void	print_infos(contact contact)
{
	std::cout << std::endl << "First name : " << contact.getFirstName() << std::endl;
	std::cout << "Last name : " << contact.getLastName() << std::endl;
	std::cout << "Nickname : " << contact.getNickname() << std::endl;
	std::cout << "Login : " << contact.getLogin() << std::endl;
	std::cout << "Postal address : " << contact.getPostalAddress() << std::endl;
	std::cout << "Email address : " << contact.getEmailAddress() << std::endl;
	std::cout << "Phone number : " << contact.getPhoneNumber() << std::endl;
	std::cout << "Birthday date : " << contact.getBirthday() << std::endl;
	std::cout << "Favorite_meal : " << contact.getFavoriteMeal() << std::endl;
	std::cout << "Underwear_color : " << contact.getUnderwearColor() << std::endl;
	std::cout << "Darkest_secret : " << contact.getDarkestSecret() << std::endl << std::endl;
}

void	print_newline(contact contact, int k)
{
	int		i;
	int		j;

	j = 0;
	std::cout << "         " << k << "|";
	i = 10 - (int)contact.getFirstName().length();
	if (i < 0)
		j = 1;
	while (--i >= 0)
		std::cout << " ";
	if (j == 1)
		std::cout << contact.getFirstName().substr(0, 9) << ".|";
	else
		std::cout << contact.getFirstName() << "|";
	i = 10 - (int)contact.getLastName().length();
	if (i < 0)
		j = 2;
	while (--i >= 0)
		std::cout << " ";
	if (j == 2)
		std::cout << contact.getLastName().substr(0, 9) << ".|";
	else
		std::cout << contact.getLastName() << "|";
	i = 10 - (int)contact.getNickname().length();
	if (i < 0)
		j = 3;
	while (--i >= 0)
		std::cout << " ";
	if (j == 3)
		std::cout << contact.getNickname().substr(0, 9) << ".\n";
	else
		std::cout << contact.getNickname() << "\n";
}

int		test_empty(contact contact)
{
	if (contact.getFirstName().compare("") != 0)
		return (0);
	if (contact.getLastName().compare("") != 0)
		return (0);
	if (contact.getNickname().compare("") != 0)
		return (0);
	if (contact.getBirthday().compare("") != 0)
		return (0);
	if (contact.getDarkestSecret().compare("") != 0)
		return (0);
	if (contact.getEmailAddress().compare("") != 0)
		return (0);
	if (contact.getPhoneNumber().compare("") != 0)
		return (0);
	if (contact.getPostalAddress().compare("") != 0)
		return (0);
	if (contact.getLogin().compare("") != 0)
		return (0);
	if (contact.getUnderwearColor().compare("") != 0)
		return (0);
	if (contact.getFavoriteMeal().compare("") != 0)
		return (0);
	return (1);
}

void	print_phone_book(contact phone_book[8])
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	std::cout << std::endl << "     index|first_name| last_name|  nickname" << std::endl;
	while (++i < 8)
	{
		if (test_empty(phone_book[i]) != 1)
		{
			j++;
			print_newline(phone_book[i], j);
		}
	}
}

void	search_contact(contact phone_book[8])
{
	std::string	input;

	if (test_empty(phone_book[0]) == 1)
	{
		std::cout << std::endl << "No contact yet.\nYou can add up to height contacts with ADD command." << std::endl << std::endl;
		return ;
	}
	print_phone_book(phone_book);
	std::cout << std::endl << "Wich contact are you interested in ?\nPlease state their index : ";
	getline(std::cin, input);
	if (input.compare("1") == 0 && test_empty(phone_book[0]) == 0)
		print_infos(phone_book[0]);
	else if (input.compare("2") == 0 && test_empty(phone_book[1]) == 0)
		print_infos(phone_book[1]);
	else if (input.compare("3") == 0 && test_empty(phone_book[2]) == 0)
		print_infos(phone_book[2]);
	else if (input.compare("4") == 0 && test_empty(phone_book[3]) == 0)
		print_infos(phone_book[3]);
	else if (input.compare("5") == 0 && test_empty(phone_book[4]) == 0)
		print_infos(phone_book[4]);
	else if (input.compare("6") == 0 && test_empty(phone_book[5]) == 0)
		print_infos(phone_book[5]);
	else if (input.compare("7") == 0 && test_empty(phone_book[6]) == 0)
		print_infos(phone_book[6]);
	else if (input.compare("8") == 0 && test_empty(phone_book[7]) == 0)
		print_infos(phone_book[7]);
	else
		std::cout << std::endl << "Come back to me when you have decided to be serious, looser." << std::endl << std::endl;
}

void	add_contact(contact phone_book[8], int *i)
{
	int			j;
	std::string	input;

	j = 0;
	while (j < 8 && test_empty(phone_book[j]) == 0 )
		j++;
	if (j == 8)
	{
		std::cout << "NOOOOO I'M FUUUUULLLL" << std::endl;
		return ;
	}
	std::cout << "First name : ";
	getline(std::cin, input);
	phone_book[j].setFirstName(input);
	std::cout << "Last name : ";
	getline(std::cin, input);
	phone_book[j].setLastName(input);
	std::cout << "Nickname : ";
	getline(std::cin, input);
	phone_book[j].setNickname(input);
	std::cout << "Login : ";
	getline(std::cin, input);
	phone_book[j].setLogin(input);
	std::cout << "Postal address : ";
	getline(std::cin, input);
	phone_book[j].setPostalAddress(input);
	std::cout << "Email address : ";
	getline(std::cin, input);
	phone_book[j].setEmailAddress(input);
	std::cout << "Phone number : ";
	getline(std::cin, input);
	phone_book[j].setPhoneNumber(input);
	std::cout << "Birthday date : ";
	getline(std::cin, input);
	phone_book[j].setBirthday(input);
	std::cout << "Favorite_meal : ";
	getline(std::cin, input);
	phone_book[j].setFavoriteMeal(input);
	std::cout << "Underwear_color : ";
	getline(std::cin, input);
	phone_book[j].setUnderwearColor(input);
	std::cout << "Darkest_secret : ";
	getline(std::cin, input);
	phone_book[j].setDarkestSecret(input);
	if (test_empty(phone_book[j]) == 0)
	{
		std::cout << std::endl << "Contact registered successfully." << std::endl << std::endl;
		(*i)++;	
	}
	else
		std::cout << std::endl << "An empty contact, AHAHA SO FUNNY AHAHA!\nCome back when you're finished with your buffooneries." << std::endl << std::endl;
}

int		main(void)
{
	contact			phone_book[8];
	std::string		input;
	int				i;

	i = 0;
	std::cout << std::endl << "* The most useful phone book humanity ever made is now opened *" << std::endl << std::endl;
	while (i != -1)
	{
		getline(std::cin, input);
		if (input.compare("ADD") == 0)
			add_contact(phone_book, &i);
		else if (input.compare("SEARCH") == 0)
			search_contact(phone_book);
		else if (input.compare("EXIT") == 0)
			i = -1;
		else
			std::cout << "Don't care" << std::endl;
	}
	std::cout << std::endl << "Every contact in this phone book is going to be lost because of you...\nI guess you are proud of you now." << std::endl << std::endl;
	std::cout << "* The most useful phone book humanity ever made is now closed *" << std::endl << std::endl;
	return (0);
}
