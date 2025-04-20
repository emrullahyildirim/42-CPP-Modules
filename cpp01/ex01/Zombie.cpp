/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:38:49 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/19 16:12:34 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << name << " Destructor called!" << std::endl;
}

void Zombie::announce()
{
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName( std::string name)
{
	this->name = name;
}
