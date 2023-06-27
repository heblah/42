/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:02:12 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/12 17:05:38 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Brain;

class Cat : public AAnimal {
	public:
						Cat(void);
						Cat(const Cat &cat);
						Cat(const std::string &type);
		virtual			~Cat(void);

		Cat &			operator=(const Cat &cat);

		void			makeSound(void) const;

		std::string		getIdea(size_t pos) const;
		void			setIdea(const std::string idea, size_t pos);

	private:
		Brain			*_brain;
};

#endif
