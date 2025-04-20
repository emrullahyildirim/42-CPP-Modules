/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:50:38 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/19 18:46:09 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		Weapon		*weapon;
		std::string	name;
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon &weapon);
		void	attack();
		
};

#endif