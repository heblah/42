/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:39:11 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/24 19:18:12 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "Brain.hpp"

class AAnimal {
	public:
						AAnimal(void);
						AAnimal(const AAnimal &animal);
						AAnimal(const std::string &type);
		virtual			~AAnimal(void);

		AAnimal &		operator=(const AAnimal &animal);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
		void			setType(const std::string &type);
		std::string		getIdea(size_t pos) const;
		void			setIdea(const std::string idea, size_t pos);

	private:
		std::string		_type;
		Brain			*_brain;
};

#endif
