/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:02:19 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/19 19:14:11 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*zombies = new Zombie[N];
	if (!zombies)
		return NULL;
	for (int i = 0; i < N; i++)
		zombies[i].setName(name);
	return zombies;
}