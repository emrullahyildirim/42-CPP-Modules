/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:00:59 by emyildir          #+#    #+#             */
/*   Updated: 2026/01/01 20:53:26 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {
		ShrubberyCreationForm shrubberyForm("treesAreCool");
		RobotomyRequestForm robotomyForm("Some Random Guy");
		PresidentialPardonForm pardonForm("Herhangi Bir Adam");

		std::cout << shrubberyForm << std::endl;
		std::cout << robotomyForm << std::endl;
		std::cout << pardonForm << std::endl;

		Bureaucrat boss("Boss", 1);
		Bureaucrat someNewGuy("SomeNewGuy", 150);
		
		std::cout << std::endl;
		std::cout << "New guy tries to sign without enough grade: " << std::endl;
		try {
			someNewGuy.signForm(shrubberyForm);
		} catch(std::exception &e) {
			std::cout << "Couldn't sign form: " << e.what() << std::endl
;		}
		std::cout << shrubberyForm << std::endl;
	
		std::cout << "Someone with power tries to sign: " << std::endl;
		try {
			boss.signForm(shrubberyForm);
			boss.signForm(robotomyForm);
			boss.signForm(pardonForm);
		} catch(std::exception &e) {
			std::cout << "Couldn't sign form: " << e.what() << std::endl;
		}
		std::cout << shrubberyForm << std::endl;
		std::cout << robotomyForm << std::endl;
		std::cout << pardonForm << std::endl;

		std::cout << std::endl;
		std::cout << "Executing forms: " << std::endl;
		try {
			someNewGuy.executeForm(shrubberyForm);
		} catch(std::exception &e) {
			std::cout << "Couldn't execute form: " << e.what() << std::endl;
		}

		boss.executeForm(shrubberyForm);
		boss.executeForm(robotomyForm);
		boss.executeForm(pardonForm);
	} catch(std::exception &e) {
		std::cout << "Couldn't initialize instances: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}

