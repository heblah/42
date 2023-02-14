/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:30:41 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/14 14:42:12 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Zombie {

	public:
		Zombie(void);
		~Zombie(void);

		void	announce(void) const;
		void	set_name(std::string name);

	private:
		std::string	_name;

};
