/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:35:58 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/17 15:58:21 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	text = "THIS IS A TEXT";
	std::string	*text_ptr = &text;
	std::string	&text_ref = text;

	std::cout << "Addresses!";
	std::cout << "Text Address: " << &text << std::endl;
	std::cout << "Address held by pointer: " << &text_ptr << std::endl;
	std::cout << "Address held by reference: " << &text_ref << std::endl;

	std::cout << "Values!";
	std::cout << "Text: " << text << std::endl;
	std::cout << "Pointer: " << *text_ptr << std::endl;
	std::cout << "Reference: " << text_ref << std::endl;
	return (EXIT_SUCCESS);
}