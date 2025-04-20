/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:35:58 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/19 17:57:38 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

int	main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Addresses:" << std::endl;
	std::cout << "String Address: " << &string << std::endl;
	std::cout << "Address held by pointer: " << &stringPTR << std::endl;
	std::cout << "Address held by reference: " << &stringREF << std::endl;

	std::cout << "Values:" << std::endl;
	std::cout << "String: " << string << std::endl;
	std::cout << "Pointer: " << *stringPTR << std::endl;
	std::cout << "Reference: " << stringREF << std::endl;
	return (EXIT_SUCCESS);
}
