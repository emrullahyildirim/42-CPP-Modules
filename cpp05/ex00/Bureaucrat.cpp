/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:01:03 by emyildir          #+#    #+#             */
/*   Updated: 2026/01/01 19:38:01 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream>

std::string intToString(int n)
{
	std::ostringstream oss;
	oss << n;
	return oss.str();
}

Bureaucrat::~Bureaucrat() {};

Bureaucrat::Bureaucrat(): _name("undefined"), _grade(150) {};

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	validateGrade(grade);
};

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	validateGrade(_grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;

	return *this;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade(int grade)
{
	int newGrade;
	
	newGrade = _grade - grade;
	validateGrade(newGrade);
	_grade = newGrade;
}

void Bureaucrat::decrementGrade(int grade)
{
	int	newGrade;

	newGrade = _grade + grade;
	validateGrade(newGrade);
	_grade = newGrade;
}

void Bureaucrat::validateGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(grade);
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException(grade);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(int grade): _message("Grade " + intToString(grade) + " is too high! Maximum grade is 1.") {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return _message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int grade) : _message("Grade " + intToString(grade) + " is too low! Minimum grade is 150.")
{
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return _message.c_str();
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";

	return stream;
}