/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:20:37 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/02 15:37:52 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class ICharacter;

class AMateria
{
	public:
							AMateria(void);
							AMateria(const AMateria & materia);
							AMateria(const std::string & type);
		virtual				~AMateria(void);

		AMateria &			operator=(const AMateria & materia);

		std::string const &	getType(void) const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter & target);

	protected:
		std::string			_type;

};

#endif
