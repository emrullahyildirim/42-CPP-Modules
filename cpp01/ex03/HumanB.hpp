/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:50:38 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/17 16:29:22 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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