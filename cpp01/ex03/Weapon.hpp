/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:34:37 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/17 16:18:11 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon {
	private:
		std::string	type;

	public: 
		Weapon( void );
		Weapon( std::string type );
		const std::string	&getType();
		void				setType( std::string type );
};

#endif