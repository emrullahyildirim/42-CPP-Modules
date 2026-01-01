/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:00:59 by emyildir          #+#    #+#             */
/*   Updated: 2026/01/01 21:07:30 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	AForm	*shrubberyForm = NULL;
	AForm	*robotomyForm = NULL;
	AForm	*pardonForm = NULL;
	
	try {
		Intern someRandomIntern;

		std::cout << std::endl << "-- Test: Intern creates non existent forms: --" << std::endl;
		AForm *nonExistentForm = someRandomIntern.makeForm("non existent form", "NoBody");
		if (nonExistentForm)
			delete nonExistentForm;

		std::cout << std::endl << "-- Test: Intern creates existent forms: --" <<  std::endl;
		shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "treesAreCool");
		robotomyForm = someRandomIntern.makeForm("robotomy request", "Some Random Guy");
		pardonForm = someRandomIntern.makeForm("presidential pardon", "Herhangi Bir Adam");

		if (!shrubberyForm || !robotomyForm || !pardonForm)
			throw std::runtime_error("Allocation of forms failed.");

		Bureaucrat boss("Boss", 1);
		boss.signForm(*shrubberyForm);
		boss.executeForm(*shrubberyForm);
		boss.signForm(*robotomyForm);
		boss.executeForm(*robotomyForm);
		boss.signForm(*pardonForm);
		boss.executeForm(*pardonForm);
		
		delete shrubberyForm;
		delete robotomyForm;
		delete pardonForm;
	} catch(std::exception &e) {
		delete shrubberyForm;
		delete robotomyForm;
		delete pardonForm;
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}

