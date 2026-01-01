/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:01:10 by emyildir          #+#    #+#             */
/*   Updated: 2026/01/01 20:46:57 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

		void		validateGrade(int grade);
	public:
		~Bureaucrat();
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);


		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade(int grade);
		void		decrementGrade(int grade);
		void		signForm(AForm &form);
		void		executeForm(AForm const &form);


		class GradeTooHighException : public std::exception
		{
			private:
				std::string	_message;
			public:
				GradeTooHighException(int grade);
				virtual ~GradeTooHighException() throw() {};
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			private:
				std::string	_message;
			public:
				GradeTooLowException(int grade);
				virtual ~GradeTooLowException() throw() {};
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);

#endif