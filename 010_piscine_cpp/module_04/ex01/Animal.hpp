/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:39:11 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/24 18:43:05 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "Brain.hpp"

class Animal {
	public:
						Animal(void);
						Animal(const Animal &animal);
						Animal(const std::string &type);
		virtual			~Animal(void);

		Animal &		operator=(const Animal &animal);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
		void			setType(const std::string &type);
		std::string		getIdea(size_t pos) const;
		void			setIdea(const std::string idea, size_t pos);

	private:
		std::string		_type;
		Brain			*_brain;
};

#endif
