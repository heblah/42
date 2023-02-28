/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:20:37 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/28 14:41:57 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure(void);
		Cure(const Cure & cure);
		Cure(std::string const & type);
		~Cure(void);

		const Cure &	operator=(const Cure & cure);

//		std::string const & getType(void) const; //Returns the materia type
		virtual Cure* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:
		std::string	_type;

};

#endif
