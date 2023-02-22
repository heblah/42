/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:36:45 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/22 09:57:16 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap 
{
	public:
						ClapTrap(void);
						ClapTrap(std::string &name);
						~ClapTrap(void);
						
		ClapTrap		operator=(const ClapTrap &claptrap);

		void			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		std::string		getName(void) const;
		std::string		getHit(void) const;
		std::string		getEnergy(void) const;

		void			setClapTrap(std::string *name, unsigned int *hit unsigned int *enegergy);
	private:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
};

#endif
