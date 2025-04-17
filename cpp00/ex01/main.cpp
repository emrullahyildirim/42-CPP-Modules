/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:34:38 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/17 15:19:37 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	input(std::string &str)
{
	std::getline(std::cin, str);
	if (std::cin.eof())
	{
		std::cout << "Eof found!" << std::endl;
		return (false);
	}
	else if (std::cin.fail())
	{
		std::cout << "Reading input failed!" << std::endl;
		return (false);
	}
	return (true);
}

int stringToInt(std::string str)
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

bool isAsciiAlpha(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		char chr = str[i];
        if (!((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z')))
            return false;
		
	}
	return (true);
}	

bool isNum(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str[i]))
            return (false);
    return (true);
}

int	Action_SearchContact(PhoneBook *phoneBook)
{
    int     contactCount = phoneBook->getContactCount();   
	if (contactCount == 0)
	{
		std::cout << "No entry found!" << std::endl;
		return (true);
	}
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
            int spaceCount = 10 - lenght > 0 ? 10 - lenght : 0;
            for (int j = 0; j < 10; j++)
            {
                if (j < spaceCount)
                    std::cout << ' ';
                else if (j == 9 && lenght > 10)
                    std::cout << '.';
                else 
                    std::cout << columns[i][j - spaceCount];
            }
            if (i == 3)
                std::cout << std::endl;
            else 
                std::cout << "|";
        }    
    }
	
    std::string userInput;
    std::cout << "Select Index To View: ";
    if (!input(userInput))
		return (false);
    if (!isNum(userInput))
    {
        std::cout << "Index can only contain numbers." << std::endl;
        return (true);
    }
    int index = stringToInt(userInput);
    if (index < 0 || index >= contactCount)
    {
		std::cout << "Index " << index << " is out of bounds. " << std::endl;
        return (true);
    }
	
    Contact contact = phoneBook->getContact(index);
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nick Name: " << contact.getNickName() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
	return (true);
}

int	Action_AddContact(PhoneBook *phoneBook)
{
    std::string inputs[5];
    std::string prompts[5] = {"Firstname", "Lastname", "Nickname", "Phone Number", "Darkest Secret"};
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << prompts[i] << ": " << std::endl;
		if (!input(inputs[i]))
			return (false);
        else if (inputs[i].length() == 0)
            std::cout << prompts[i--] << " can't be empty!" << std::endl;
		else if (i != 3 && !isAsciiAlpha(inputs[i]))
            std::cout << prompts[i--] << " can't contain non-alpha characters!" << std::endl;
		else if (i == 3 && !isNum(inputs[i]))
			std::cout << prompts[i--] << " can only contain numbers!" << std::endl;
    }
    phoneBook->Add(inputs[0], inputs[1], inputs[2], inputs[3], inputs[4]);
	return (true);
}

int main()
{
    PhoneBook   phoneBook;
    std::string option;
    
    while (true)
    {
        std::cout << "What do you want to do? (ADD, SEARCH, EXIT)" << std::endl << "> ";
        if (!input(option))
		    return (EXIT_FAILURE);
        if (!option.compare("EXIT"))
            break ; 
        else if ((!option.compare("ADD") && !Action_AddContact(&phoneBook)) 
			|| (!option.compare("SEARCH") && !Action_SearchContact(&phoneBook)))
			return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}