/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:20:35 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/29 19:04:51 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
						FragTrap(void);
						FragTrap(const FragTrap &frag);
						FragTrap(const std::string &name);
						~FragTrap(void);

		FragTrap &		operator=(const FragTrap &frag);

		void			highFivesGuys(void) const;

};

#endif
