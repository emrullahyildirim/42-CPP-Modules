/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:34:41 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/18 21:04:30 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {
    private:
        Contact _contacts[8];
        int     _count;
    public:
        PhoneBook();
        Contact		getContact(int index);
        int			getContactCount();
        void		Add(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
};

#endif