/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:16:02 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/03 15:44:39 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP 

#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
	public:
					MateriaSource(void);
					MateriaSource(const MateriaSource &m);
					~MateriaSource(void);

		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);

	private:
		AMateria	*_materia[4];
};

#endif /* MATERIASOURCE_HPP */
