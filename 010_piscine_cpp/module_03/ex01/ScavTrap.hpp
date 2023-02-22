/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:06:17 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/22 15:51:05 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
				ScavTrap(void);
				ScavTrap(const std::string &name);
				~ScavTrap(void);

		void	guardGate(void);

	private:
};

#endif
