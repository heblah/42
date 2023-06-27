/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:39:11 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/24 14:46:41 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

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

	private:
		std::string		_type;
};

#endif
