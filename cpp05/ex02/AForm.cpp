/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 22:16:29 by emyildir          #+#    #+#             */
/*   Updated: 2026/01/01 20:40:02 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

void	AForm::validateGrade(int requiredGradeToSign, int requiredGradeToExecute)
{
	if (requiredGradeToSign < 1 || requiredGradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (requiredGradeToSign > 150 || requiredGradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
}

AForm::AForm() : _name("undefined"),  _requiredGradeToSign(150), _requiredGradeToExecute(150), _signed(false)
{
}

AForm::AForm(std::string name, int requiredGradeToExecute, int requiredGradeToSign) : _name(name), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute), _signed(false)
{
	validateGrade(_requiredGradeToSign, _requiredGradeToExecute);
}

AForm::AForm(const AForm& other) : _name(other._name), _requiredGradeToSign(other._requiredGradeToSign), _requiredGradeToExecute(other._requiredGradeToExecute), _signed(false)
{
	validateGrade(_requiredGradeToSign, _requiredGradeToExecute);
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

int	AForm::getRequiredGradeToExecute() const 
{
	return _requiredGradeToExecute;
}

int	AForm::getRequiredGradeToSign() const 
{
	return _requiredGradeToSign;
}

bool AForm::getSigned() const 
{
	return _signed;
}


std::string AForm::getName() const 
{
	return _name;
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _requiredGradeToSign)
		throw	AForm::GradeTooLowException();

	_signed = true;
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (!_signed)
		throw	AForm::NotSignedException();
	if (executor.getGrade() > _requiredGradeToExecute)
		throw	AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form is not signed.";
}

std::ostream &operator<<(std::ostream &stream, const AForm &form)
{
	stream 
	<< form.getName() << " is" << (form.getSigned() ? "" : " not") 
	<< " signed, required grade to sign is " << form.getRequiredGradeToSign() 
	<< ", required grade to execute is " << form.getRequiredGradeToExecute()
	<< ".";
	return stream;
}


