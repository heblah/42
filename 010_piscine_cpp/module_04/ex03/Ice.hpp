/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:20:37 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/28 19:36:16 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria {
	public:
							Ice(void);
							Ice(const Ice & ice);
							Ice(std::string const & type);
							~Ice(void);

		const Ice &			operator=(const Ice & ice);

		std::string const &	getType(void) const; //Returns the materia type
		AMateria *			clone(void) const;
		void				use(ICharacter & target) const;

	protected:
		std::string	_type;

};

#endif