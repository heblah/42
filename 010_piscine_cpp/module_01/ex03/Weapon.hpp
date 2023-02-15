/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:26:26 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/15 18:20:51 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

class Weapon {

	public:
							Weapon(std::string type);
		const std::string&	getType(void) const;
		void				setType(std::string type);

	private:
		std::string	_type;

};

#endif
