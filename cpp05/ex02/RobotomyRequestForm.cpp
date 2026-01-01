/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 23:41:49 by emyildir          #+#    #+#             */
/*   Updated: 2026/01/01 20:55:30 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 45, 72), _target("undefined")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 45, 72), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), other.getRequiredGradeToSign(), other.getRequiredGradeToExecute())
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	(void)other;
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	RobotomyRequestForm::AForm::execute(executor);

	std::cout << "*Some voices that seems like drilling*" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " is now robotomizated!" << std::endl;
	else
		std::cout << "failed to robotomize " << _target << "." << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const RobotomyRequestForm &form)
{
	stream
		<< form.getName() << " is" << (form.getSigned() ? "" : " not")
		<< " signed, required grade to sign is " << form.getRequiredGradeToSign()
		<< ", required grade to execute is " << form.getRequiredGradeToExecute()
		<< " and the target is " << form.getTarget()
		<< ".";
	return stream;
}
