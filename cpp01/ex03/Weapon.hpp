/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:34:37 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/19 19:30:32 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon {
	private:
		std::string	type;

	public: 
		Weapon( std::string type );
		const std::string	&getType();
		void				setType( std::string type );
};

#endif