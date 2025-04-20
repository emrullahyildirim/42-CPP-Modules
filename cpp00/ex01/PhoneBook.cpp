/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:56:26 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/18 21:06:23 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    _count = 0;
};

void PhoneBook::Add(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	int	index = _count % 8;
    _contacts[index].setAttributes(firstName, lastName, nickName, phoneNumber, darkestSecret);
	_count++;
}

int PhoneBook::getContactCount()
{
    return (_count < 8 ? _count : 8);
}

Contact PhoneBook::getContact(int index)
{
    return (_contacts[index]);
}