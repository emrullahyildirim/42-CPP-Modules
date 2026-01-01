/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:45:54 by emyildir          #+#    #+#             */
/*   Updated: 2026/01/01 20:39:29 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat; 

class AForm
{
	private:
		const std::string _name;
		const int _requiredGradeToSign;
		const int _requiredGradeToExecute;
		bool _signed;

		void		validateGrade(int requiredGradeToSign, int requiredGradeToExecute);
	public:
		AForm();
		virtual ~AForm();
		AForm(std::string name, int requiredGradeToExecute, int requiredGradeToSign);
		AForm(const AForm &other);
		AForm& operator=(const AForm& other);

		int				getRequiredGradeToSign() const;
		int				getRequiredGradeToExecute() const;
		bool			getSigned() const;
		std::string		getName() const;	
		void			beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const& executor) const = 0;
		
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

		class NotSignedException : public std::exception
		{
			public:
				virtual ~NotSignedException() throw() {};
				const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& stream, const AForm& form);

#endif