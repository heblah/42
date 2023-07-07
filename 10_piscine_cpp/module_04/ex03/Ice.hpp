/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:20:37 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/03 09:02:18 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
	public:
							Ice(void);
							Ice(const Ice & ice);
							Ice(std::string const & type);
							~Ice(void);

		Ice &				operator=(const Ice & ice);

		std::string const &	getType(void) const; //Returns the materia type
		AMateria *			clone(void) const;
		void				use(ICharacter & target);

	protected:
		std::string			_type;

};

#endif