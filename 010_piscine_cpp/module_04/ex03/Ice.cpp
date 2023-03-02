/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:23:46 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/02 16:36:46 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"

/* Constructors ============================================================= */
Ice::Ice(void) : AMateria()
{
	this->_type = "ice";
	return;
}

Ice::Ice(const Ice &ice) : AMateria(ice)
{
	this->_type = ice._type;
	return;
}

Ice::Ice(const std::string & type) : AMateria(type)
{
	return;
}

/* Destructors ============================================================== */
Ice::~Ice(void)
{
	return;
}

/* Operators ================================================================ */
const Ice	&Ice::operator=(const Ice &ice __attribute__((unused)))
{
	//this->_type = materia._type;
	return (*this);
}

/* Member functions ========================================================= */
std::string const &	Ice::getType(void) const
{
	return (this->_type);
}

AMateria	*Ice::clone(void) const
{
	return (new Ice);
}

void	Ice::use(ICharacter& target) const
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return;
}
