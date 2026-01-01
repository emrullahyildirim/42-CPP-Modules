/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 22:16:29 by emyildir          #+#    #+#             */
/*   Updated: 2026/01/01 20:36:24 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

void	Form::validateGrade(int requiredGradeToSign, int requiredGradeToExecute)
{
	if (requiredGradeToSign < 1 || requiredGradeToExecute < 1)
	throw Form::GradeTooHighException();
	if (requiredGradeToSign > 150 || requiredGradeToExecute > 150)
	throw Form::GradeTooLowException();
}

Form::~Form()
{
	
}

Form::Form() : _name("undefined"),  _requiredGradeToSign(150), _requiredGradeToExecute(150), _signed(false)
{
}

Form::Form(std::string name, int requiredGradeToExecute, int requiredGradeToSign) : _name(name), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute), _signed(false)
{
	validateGrade(_requiredGradeToSign, _requiredGradeToExecute);
}

Form::Form(const Form& other) : _name(other._name), _requiredGradeToSign(other._requiredGradeToSign), _requiredGradeToExecute(other._requiredGradeToExecute), _signed(false)
{
	validateGrade(_requiredGradeToSign, _requiredGradeToExecute);
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

int	Form::getRequiredGradeToExecute() const 
{
	return _requiredGradeToExecute;
}

int	Form::getRequiredGradeToSign() const 
{
	return _requiredGradeToSign;
}

bool Form::getSigned() const 
{
	return _signed;
}

std::string Form::getName() const 
{
	return _name;
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _requiredGradeToSign)
		throw	Form::GradeTooLowException();

	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too high.";
}

std::ostream &operator<<(std::ostream &stream, const Form &form)
{
	stream 
	<< form.getName() << " is" << (form.getSigned() ? "" : " not") 
	<< " signed, required grade to sign is " << form.getRequiredGradeToSign() 
	<< ", required grade to execute is " << form.getRequiredGradeToExecute()
	<< ".";
	return stream;
}


