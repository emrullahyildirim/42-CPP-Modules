/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:00:59 by emyildir          #+#    #+#             */
/*   Updated: 2026/01/01 20:34:19 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat boss("Boss", 1);
		Bureaucrat someNewGuy("SomeNewGuy", 150);
		Form form("Top Secret Form", 35, 20);

		std::cout << form << std::endl << std::endl;
		
		std::cout << "New guy tries to sign without enough grade: " << std::endl;
		try {
			someNewGuy.signForm(form);
		} catch(std::exception &e) {
			std::cout << "Couldn't sign form: " << e.what() << std::endl;
		}
		std::cout << form << std::endl;
	
		std::cout << std::endl;
	
		std::cout << "Someone with power tries to sign: " << std::endl;
		try {
			boss.signForm(form);
		} catch(std::exception &e) {
			std::cout << "Couldn't sign form: " << e.what() << std::endl;
		}
		std::cout << form << std::endl;

	} catch(std::exception &e) {
		std::cout << "Couldn't initialize instances: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}

