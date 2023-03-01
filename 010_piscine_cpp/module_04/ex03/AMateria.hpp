/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:20:37 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/01 09:45:54 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "Character.hpp"

class AMateria
{
	public:
							AMateria(void);
							AMateria(const AMateria & materia);
							AMateria(const std::string & type);
		virtual				~AMateria(void);

		const AMateria &	operator=(const AMateria & materia);

		std::string const &	getType(void) const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
//		virtual void		use(ICharacter & target);

	protected:
		std::string			_type;

};

#endif
