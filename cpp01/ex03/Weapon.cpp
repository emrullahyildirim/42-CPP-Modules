/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:37:50 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/17 16:31:19 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string	&Weapon::getType()
{
	return type;
}

void	Weapon::setType( std::string type )
{
	this->type = type;
}

Weapon::Weapon( void )
{
	this->type = type;
}

Weapon::Weapon( std::string type ) : type(type)
{
}