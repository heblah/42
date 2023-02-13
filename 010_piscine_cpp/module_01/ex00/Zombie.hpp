/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:30:41 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/13 19:36:18 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Zombie {

	public:
		Zombie(std::string name);
		void	announce(void) const;

	private:
		std::string	_name;

};
