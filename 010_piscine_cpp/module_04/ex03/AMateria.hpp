/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:20:37 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/28 20:22:21 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

//#include "ICharacter.hpp"

class AMateria
{
	public:
							AMateria(void);
							AMateria(const AMateria & materia);
							AMateria(std::string const & type);
							~AMateria(void);

		const AMateria &	operator=(const AMateria & materia);

		std::string const &	getType(void) const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
//		virtual void		use(ICharacter& target);

	protected:
		std::string			_type;

};

#endif
