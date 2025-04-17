/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:51:06 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/17 15:41:58 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*zombie = newZombie("Rick");
	if (!zombie)
		std::cout << "Allocation error!" << std::endl;
	randomChump("Daryl");	
	zombie->announce();
	zombie->announce();
	delete zombie;
}