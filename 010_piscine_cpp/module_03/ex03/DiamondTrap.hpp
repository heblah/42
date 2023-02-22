/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:53:41 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/22 17:20:23 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ClapTrap, public FragTrap
{
	public:
				DiamondTrap(void);
				DiamondTrap(const std::string &name);
				~DiamondTrap(void);

	void		whoAmI(void) const;

	private:
		std::string	_name;

};

#endif
