/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:14:06 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/19 17:54:50 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Zombie.hpp"

int	main()
{
	const int	zombie_count	= 10;
	Zombie		*zombies = zombieHorde(zombie_count, "Carl");

	if (!zombies)
	{
		std::cout << "Allocation Error";
		return (EXIT_FAILURE); 
	}
	for (int i = 0; i < zombie_count; i++)
		zombies[i].announce();
	delete []zombies;
	return (EXIT_SUCCESS);
}