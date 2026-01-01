/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 23:41:49 by emyildir          #+#    #+#             */
/*   Updated: 2026/01/01 20:44:20 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 137, 145), _target("undefined")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 137, 145), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), other.getRequiredGradeToSign(), other.getRequiredGradeToExecute())
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	(void)other;
	return *this;
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	ShrubberyCreationForm::AForm::execute(executor);

	std::ofstream file;
	file.open((_target + "_shrubbery").c_str(), std::ios::out);
	if (file.is_open())
	{

		file << "\toxoxoo\tooxoo\n  ooxoxo oo  oxoxooo\n oooo xxoxoo ooo ooox\n oxo o oxoxo  xoxxoxo\n  oxo xooxoooo o ooo\n\tooo\\oo\\  /o/o\n\t\t\\  \\/ /\n\t\t |   /\n\t\t |  |\n\t\t |  |\n\t\t |  |\n\t\t |  |\n  ______/____\\____";
	}
	else
		std::cout << "Couldn't open the file to write the tree." << std::endl;
}

std::ostream &operator<<(std::ostream &stream, const ShrubberyCreationForm &form)
{
	stream
		<< form.getName() << " is" << (form.getSigned() ? "" : " not")
		<< " signed, required grade to sign is " << form.getRequiredGradeToSign()
		<< ", required grade to execute is " << form.getRequiredGradeToExecute()
		<< " and the target is " << form.getTarget()
		<< ".";
	return stream;
}
