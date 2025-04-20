/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:50:38 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/19 18:45:53 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
		std::string	name;
		Weapon		&weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack();
};

#endif
