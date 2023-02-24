/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:02:12 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/24 12:23:08 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public:
				Dog(void);
				Dog(const Dog &dog);
				~Dog(void);

		Dog &	operator=(const Dog &dog);

		void	makeSound(void) const;

	private:
}

#endif
