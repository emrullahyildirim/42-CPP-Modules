/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:38:49 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/17 16:31:00 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

void Zombie::announce()
{
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName( std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << " Destructor called!" << std::endl;
}