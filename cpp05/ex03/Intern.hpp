/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:35:23 by emyildir          #+#    #+#             */
/*   Updated: 2025/12/31 22:06:13 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"

class Intern
{
	private:
		static AForm	*createPresidentialPardonForm(std::string target);
		static AForm	*createRobotomyRequestForm(std::string target);
		static AForm	*createShrubberyCreationForm(std::string target);
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		
		
		AForm	*makeForm(std::string name, std::string target);

};