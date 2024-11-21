/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:34:38 by emyildir          #+#    #+#             */
/*   Updated: 2024/11/21 21:42:43 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int string_to_int(std::string str)
{
    int     num;
    int     sign;
    int     i;
    
    sign = 1;
    num = 0;
    i = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign =  -1; 
        i++;
    }
    while (std::isdigit(str[i]))
    {
        num = (num * 10) + (str[i] - '0');
        i++;
    }
    return (num * sign);
}

bool is_valid_index(std::string str)
{
    for (int i = 0; i < str[i]; i++)
        if (!std::isdigit(str[i]))
            return (false);
    return (true);
}

void Action_SearchContact(PhoneBook *phoneBook)
{
    int     contactCount = phoneBook->getContactCount();   
    for (int i = 0; i < contactCount; i++)
    {
        Contact contact = phoneBook->getContact(i);
        
        std::string columns[4] = {
            "",
            contact.getFirstName(),
            contact.getLastName(),
            contact.getNickName()
        };
        columns[0] = i + '0';
        for (int i = 0; i < 4; i++)
        {
            int lenght = columns[i].length();
            int space_count = 10 - lenght > 0 ? 10 - lenght : 0;
            for (int j = 0; j < 10; j++)
            {
                if (j < space_count)
                    std::cout << ' ';
                else if (j == 9 && lenght > 10)
                    std::cout << '.';
                else 
                    std::cout << columns[i][j - space_count];
            }
            if (i == 3)
                std::cout << std::endl;
            else 
                std::cout << "|";
        }    
    }
    std::string input;
    std::cout << "Select Index To View: ";
    std::cin >> input;
    if (!is_valid_index(input))
    {
        std::cout << "Index can only contain numbers." << std::endl;
        return ;
    }
    int index = string_to_int(input);
    if (index < 0 || index > contactCount)
    {
        std::cout << "Index should be between 0 and " << contactCount << "." << std::endl;
        return ;
    }
    Contact contact = phoneBook->getContact(index);
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " <<contact.getLastName() << std::endl;
    std::cout << "Nick Name: " <<contact.getNickName() << std::endl;
    std::cout << "Phone Number: " <<contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " <<contact.getDarkestSecret() << std::endl;
}

void Action_AddContact(PhoneBook *phoneBook)
{
    std::string inputs[5];
    std::string prompts[5] = {"Firstname", "Lastname", "Nickname", "Phone Number", "Darkest Secret"};
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << prompts[i] << ": " << std::endl;
        std::cin >> inputs[i];
        if (inputs[i].length() == 0)
            std::cout << prompts[i--] << " can't be empty!" << std::endl;
    }
    phoneBook->Add(inputs[0], inputs[1], inputs[2], inputs[3], inputs[4]);
}

int main()
{
    PhoneBook phoneBook;
    
    std::string input;
    while (true)
    {
        std::cout << "What do you want to do? (ADD, SEARCH, EXIT)" << std::endl << "> ";
        std::cin >> input;
        if (!input.compare("EXIT"))
            break ; 
        else if (!input.compare("ADD"))
            Action_AddContact(&phoneBook);
        else if (!input.compare("SEARCH"))
            Action_SearchContact(&phoneBook);
    }
    return (0);
}