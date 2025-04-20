/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:37:50 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/19 19:32:43 by emyildir         ###   ########.fr       */
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

Weapon::Weapon( std::string type ) : type(type)
{
}