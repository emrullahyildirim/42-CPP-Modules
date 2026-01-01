/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:45:54 by emyildir          #+#    #+#             */
/*   Updated: 2026/01/01 20:34:56 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat; 

class Form
{
	private:
		const std::string _name;
		const int _requiredGradeToSign;
		const int _requiredGradeToExecute;
		bool _signed;

		void		validateGrade(int requiredGradeToSign, int requiredGradeToExecute);
	public:
		Form();
		~Form();
		Form(std::string name, int requiredGradeToExecute, int requiredGradeToSign);
		Form(const Form &other);
		Form& operator=(const Form& other);

		int			getRequiredGradeToSign() const;
		int			getRequiredGradeToExecute() const;
		bool		getSigned() const;
		std::string	getName() const;	
		void		beSigned(Bureaucrat &bureaucrat);
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual ~GradeTooHighException() throw() {};
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual ~GradeTooLowException() throw() {};
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& stream, const Form& form);

#endif