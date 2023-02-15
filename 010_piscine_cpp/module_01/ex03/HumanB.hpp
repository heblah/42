/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:34:45 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/15 18:55:53 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {

	public:
				HumanB(std::string name);
		void	setWeapon(Weapon &weapon);
		void	attack(void) const;

	private:
		std::string	_name;
		Weapon		*_weapon;

};

#endif
