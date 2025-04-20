/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:34:34 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/18 21:05:40 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact {
    private: 
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;
    public:
        Contact();
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
        void		setAttributes(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
};

#endif