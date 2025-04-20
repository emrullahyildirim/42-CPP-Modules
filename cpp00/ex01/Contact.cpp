/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:47:13 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/18 21:06:05 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

void    Contact::setAttributes(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
    _firstName = firstName;
    _lastName = lastName;
    _nickName = nickName;
    _phoneNumber = phoneNumber;
    _darkestSecret = darkestSecret;
}

std::string Contact::getFirstName()
{
    return (_firstName);
}

std::string Contact::getLastName()
{
    return (_lastName);
}

std::string Contact::getNickName()
{
    return (_nickName);
}

std::string Contact::getPhoneNumber()
{
    return (_phoneNumber);
}

std::string Contact::getDarkestSecret()
{
    return (_darkestSecret);
}