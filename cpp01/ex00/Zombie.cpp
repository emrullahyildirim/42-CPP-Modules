/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:38:49 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/19 15:59:14 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( std::string name ) : name(name)
{
}

Zombie::~Zombie()
{
	std::cout << name << " Destructor called!" << std::endl;
}