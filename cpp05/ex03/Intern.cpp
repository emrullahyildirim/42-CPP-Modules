/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:37:23 by emyildir          #+#    #+#             */
/*   Updated: 2025/12/31 22:07:21 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm	*Intern::createRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm	*Intern::createShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::createPresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *form;

	std::string formNames[] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	
	AForm *(*formCreators[])(std::string) = {
		&Intern::createPresidentialPardonForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createShrubberyCreationForm
	};
	
	form = NULL;
	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std::cout << "Intern creates " << name << " form." << std::endl;
			form = formCreators[i](target);
		}
	}
	if (form == NULL)
		std::cout << "Intern could not find the form: " << name << std::endl;
	return form;
}
