/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:43:30 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/03 15:51:39 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

/* Constructors ============================================================= */
MateriaSource::MateriaSource(void) : IMateriaSource()
{
	int	idx = 0;

	while (idx < 4)
	{
		_materia[idx] = NULL;
		idx++;
	}
	return;
}

MateriaSource::MateriaSource(const MateriaSource & m) : IMateriaSource(m)
{
	int	idx = 0;

	while (idx < 4)
	{
		if (this->_materia[idx] != NULL)
		{
			delete this->_materia[idx];
			this->_materia[idx] = NULL;
		}
		if (this->_materia[idx] == NULL && m._materia[idx] != NULL)
			this->_materia[idx] = m._materia[idx]->clone();
		else
			this->_materia[idx] = NULL;
		idx++;
	}
	return;
}

/* Destructor =============================================================== */
MateriaSource::~MateriaSource(void)
{
	int	idx = 0;

	while (idx < 4)
	{
		if (this->_materia[idx] != NULL)
			delete this->_materia[idx];
		idx++;
	}
	return;
}

/* Member functions ========================================================= */
void	MateriaSource::learnMateria(AMateria *m)
{
	int	idx = 0;

	while (idx < 4)
	{
		if (this->_materia[idx] == NULL)
		{
			this->_materia[idx] = m;
			return;
		}
		idx++;
	}
	return;
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	if (type.compare("ice") == 0)
		return (new Ice);
	else if (type.compare("cure") == 0)
		return (new Cure);
	else
		return (NULL);
}
