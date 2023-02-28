/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:23:46 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/28 12:53:12 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Ice.hpp"

/* Constructors ============================================================= */
Ice::Ice(void)
{
	return;
}

Ice::Ice(const Ice &ice)
{
	this->_type = ice._type;
	return;
}

Ice::Ice(const std::string & type) : _type(type)
{
	return;
}

/* Destructors ============================================================== */
Ice::~Ice(void)
{
	return;
}

/* Operators ================================================================ */
const Ice	&Ice::AMateria(const Ice &ice)
{
	//this->_type = materia._type;
	return (*this);
}

/* Member functions ========================================================= */
std::string const &	getType(void) const
{
	return (this->_type);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
	return;
}
