/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 23:41:49 by emyildir          #+#    #+#             */
/*   Updated: 2026/01/01 20:43:20 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 5, 25), _target("undefined")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 5, 25), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.getName(), other.getRequiredGradeToSign(), other.getRequiredGradeToExecute())
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	(void)other;
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	PresidentialPardonForm::AForm::execute(executor);

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const PresidentialPardonForm &form)
{
	stream
		<< form.getName() << " is" << (form.getSigned() ? "" : " not")
		<< " signed, required grade to sign is " << form.getRequiredGradeToSign()
		<< ", required grade to execute is " << form.getRequiredGradeToExecute()
		<< " and the target is " << form.getTarget()
		<< ".";
	return stream;
}
