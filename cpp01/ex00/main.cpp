/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:51:06 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/19 17:50:55 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
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
	return (EXIT_SUCCESS);
}