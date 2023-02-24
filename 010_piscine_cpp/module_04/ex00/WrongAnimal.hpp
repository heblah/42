/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:39:11 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/24 16:10:20 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

class WrongAnimal {
	public:
						WrongAnimal(void);
						WrongAnimal(const WrongAnimal &wanimal);
						WrongAnimal(const std::string &type);
		virtual			~WrongAnimal(void);

		WrongAnimal &		operator=(const WrongAnimal &wanimal);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
		void			setType(const std::string &type);

	private:
		std::string		_type;
};

#endif
