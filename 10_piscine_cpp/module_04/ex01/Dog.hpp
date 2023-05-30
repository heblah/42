/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:02:12 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/12 16:12:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Brain;

class Dog : public Animal {
	public:
						Dog(void);
						Dog(const Dog &dog);
						Dog(const std::string &type);
		virtual			~Dog(void);

		Dog &			operator=(const Dog &dog);

		void			makeSound(void) const;

		std::string		getIdea(size_t pos) const;
		void			setIdea(const std::string idea, size_t pos);

	private:
		Brain			*_brain;
};

#endif
