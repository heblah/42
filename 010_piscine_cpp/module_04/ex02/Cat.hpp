/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:02:12 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/24 19:18:40 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public AAnimal {
	public:
				Cat(void);
				Cat(const Cat &cat);
				Cat(const std::string &type);
				~Cat(void);

		Cat &	operator=(const Cat &cat);

		void	makeSound(void) const;

	private:
};

#endif