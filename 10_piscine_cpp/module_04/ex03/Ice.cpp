/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:23:46 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/31 12:06:51 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

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
Ice	&Ice::operator=(const Ice &ice __attribute__((unused)))
{
	return (*(new Ice));
}

/* Member functions ========================================================= */
std::string const &	Ice::getType(void) const
{
	return (this->_type);
}

AMateria	*Ice::clone(void) const
{
	return (new Ice( this->_type ));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return;
}