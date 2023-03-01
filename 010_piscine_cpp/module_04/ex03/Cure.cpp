/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:23:46 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/01 09:38:18 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ICharacter.hpp"
//#include "Cure.hpp"

/* Constructors ============================================================= */
Cure::Cure(void)
{
	return;
}

Cure::Cure(const Cure &cure)
{
	this->_type = cure._type;
	return;
}

Cure::Cure(const std::string & type) : _type(type)
{
	return;
}

/* Destructors ============================================================== */
Cure::~Cure(void)
{
	return;
}

/* Operators ================================================================ */
const Cure	&Cure::operator=(const Cure &cure)
{
	//this->_type = materia._type;
	return (*this);
}

/* Member functions ========================================================= */
std::string const &	Cure::getType(void) const
{
	return (this->_type);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return;
}
