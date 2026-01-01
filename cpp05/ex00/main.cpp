/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:00:59 by emyildir          #+#    #+#             */
/*   Updated: 2026/01/01 19:45:43 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{	
	std::cout << "-- TEST: Initializing with out of bounds grade. --" << std::endl;
	std::cout << "1- Grade too high (0):" << std::endl << "Expected: GradeTooHighException" << std::endl << "Result: ";
	try {
		Bureaucrat bureaucrat("Herhangi bir adam", 0); 
		std::cout << bureaucrat;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "2- Grade too low (165):" << std::endl << "Expected: GradeTooLowException" << std::endl << "Result: ";
	try {
		Bureaucrat bureaucrat("Herhangi bir adam", 165);
		std::cout << bureaucrat;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "-- TEST: Initializing with legit grade. --" << std::endl;
	std::cout << "1- Grade 3:" << std::endl << "Expected: Bureaucrat with grade 3" << std::endl << "Result: ";

	try {
		Bureaucrat bureaucrat("Herhangi bir adam", 3);
		std::cout << bureaucrat << std::endl;

		std::cout << std::endl << "-- TEST: Incrementing and decrementing grade. --" << std::endl;
		std::cout << "At Start: " << bureaucrat << std::endl;
		try {
			std::cout << "1- Decrementing 10." << std::endl << "Expected: Bureaucrat with grade 13" << std::endl << "Result: ";
			bureaucrat.decrementGrade(10);
			std::cout << bureaucrat << std::endl;
			std::cout << "2- Decrementing 160." << std::endl << "Expected: GradeTooLowException" << std::endl << "Result: ";
			bureaucrat.decrementGrade(160);
			std::cout << bureaucrat << std::endl; 
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << "After Decrementing: " << bureaucrat << std::endl << std::endl;
		
		std::cout << std::endl << "Incrementing grade:" << std::endl;
		std::cout << "At Start: " << bureaucrat << std::endl;
		try {
			std::cout << "1- Increment 10." << std::endl << "Expected: Bureaucrat with grade 3" << std::endl << "Result: ";
			bureaucrat.incrementGrade(10);
			std::cout << bureaucrat << std::endl;
			std::cout << "2- Increment 160." << std::endl << "Expected: GradeTooHighException" << std::endl << "Result: ";
			bureaucrat.incrementGrade(160);
			std::cout << bureaucrat << std::endl; 
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "After incrementing: " << bureaucrat << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	
	return (0);
}

