/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:36:45 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/22 19:16:14 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap 
{
	public:
						ClapTrap(void);
						ClapTrap(const ClapTrap &clap);
						ClapTrap(const std::string &name);
						~ClapTrap(void);
						
		ClapTrap &		operator=(const ClapTrap &claptrap);

		void			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		std::string		getName(void) const;
		unsigned int	getHit(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getAttack(void) const;

		void			setClapTrap(const std::string *name, const unsigned int *hit,
							const unsigned int *energy, const unsigned int *attack);
	private:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
};

#endif
