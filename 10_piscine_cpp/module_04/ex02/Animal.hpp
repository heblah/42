/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:39:11 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/12 17:00:40 by halvarez         ###   ########.fr       */
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

	private:
		std::string		_type;
};

#endif
