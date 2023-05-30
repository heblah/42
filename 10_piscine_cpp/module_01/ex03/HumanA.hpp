/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:34:45 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/14 19:01:00 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {

	public:
				HumanA(std::string name, Weapon &weapon);
		void	setWeapon(Weapon weapon);
		void	attack(void) const;

	private:
		std::string	_name;
		Weapon		&_weapon;

};

#endif
