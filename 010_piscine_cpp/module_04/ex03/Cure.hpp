/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:20:37 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/02 15:37:46 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

class ICharacter;

class Cure : public AMateria
{
	public:
							Cure(void);
							Cure(const Cure & cure);
							Cure(std::string const & type);
							~Cure(void);

		const Cure &		operator=(const Cure & cure);

		std::string const & getType(void) const; //Returns the materia type
		AMateria *			clone(void) const;
		void				use(ICharacter & target);

	protected:
		std::string			_type;

};

#endif
