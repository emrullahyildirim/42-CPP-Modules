/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:56:26 by emyildir          #+#    #+#             */
/*   Updated: 2024/11/21 19:19:59 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook()
{
    _count = 0;
};

void PhoneBook::Add(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
    _contacts[_count % 7].set_attributes(firstName, lastName, nickName, phoneNumber, darkestSecret);
    _count++;
}

int PhoneBook::getContactCount()
{
    return (_count % 7);
}

Contact PhoneBook::getContact(int index)
{
    return (_contacts[index]);
}