/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:30:48 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/28 20:17:23 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP 

#include "AMateria.hpp"
//#include "Cure.hpp"
//#include "Ice.hpp"

class ICharacter {
	public:
		virtual						~ICharacter(void);

		virtual std::string	const &	getName(void) const = 0;
		
		virtual void				equip(AMateria *m);
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter& target) = 0;

};

#endif /* CHARACTER_HPP */
