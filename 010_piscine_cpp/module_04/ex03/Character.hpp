/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:30:48 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/02 18:19:01 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP 

#include "ICharacter.hpp"
//#include "Cure.hpp"
//#include "Ice.hpp"

class AMateria;

class Character : public ICharacter
{
	public:
							Character(void);
							Character(const Character & character);
							Character(const std::string &name);
							~Character(void);

		Character &			operator=(const Character & character);

		std::string	const &	getName(void) const;
		
		void				setName(const std::string &name);
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

	private:
		std::string			_name;
		AMateria			*_inventory[4];

};

#endif /* CHARACTER_HPP */
