/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:34:34 by emyildir          #+#    #+#             */
/*   Updated: 2024/11/21 20:14:18 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

class Contact {
    private: 
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;
    public:
        Contact();
        void    set_attributes(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();      
        std::string getPhoneNumber();
        std::string getDarkestSecret();
};