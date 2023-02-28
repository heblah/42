/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:16:02 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/28 17:16:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP 

class IMateriaSource
{
	public:
				~IMateriaSource() {};
		void	learnMateria(AMateria*) = 0;
				AMateria* createMateria(std::string const & type) = 0;
};

#endif /* MATERIASOURCE_HPP */
