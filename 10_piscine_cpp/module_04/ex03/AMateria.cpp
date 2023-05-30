/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:23:46 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/02 18:16:03 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

/* Constructors ============================================================= */
AMateria::AMateria(void)
{
	return;
}

AMateria::AMateria(const AMateria &materia)
{
	this->_type = materia._type;
	return;
}

AMateria::AMateria(const std::string & type) : _type(type)
{
	return;
}

/* Destructors ============================================================== */
AMateria::~AMateria(void)
{
	return;
}

/* Operators ================================================================ */
AMateria &	AMateria::operator=(const AMateria &materia __attribute__((unused)))
{
	//this->_type = materia._type;
	return (*this);
}

/* Member functions ========================================================= */
std::string const &	AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target __attribute__((unused)))
{
	std::cout << "Using Abstract Materia doesn't make any sense !" << std::endl;
	return;
}
