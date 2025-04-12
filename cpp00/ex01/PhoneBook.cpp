/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:56:26 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/12 19:21:33 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook()
{
    _count = 0;
};

void PhoneBook::Add(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
    _contacts[_count].setAttributes(firstName, lastName, nickName, phoneNumber, darkestSecret);
    _count = (_count + 1) % 8;
}

int PhoneBook::getContactCount()
{
    return (_count % 8);
}

Contact PhoneBook::getContact(int index)
{
    return (_contacts[index]);
}