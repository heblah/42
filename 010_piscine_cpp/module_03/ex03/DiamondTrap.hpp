/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:53:41 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/23 14:43:38 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
	public:
					DiamondTrap(void);
					DiamondTrap(const DiamondTrap &diamond);
					DiamondTrap(const std::string &name);
					~DiamondTrap(void);

	DiamondTrap &	operator=(const DiamondTrap &diamond);

	void			attack(const std::string &target);
	void			whoAmI(void) const;

	private:
		std::string	_name;

};

#endif
