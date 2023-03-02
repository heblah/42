/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:23:46 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/02 16:46:02 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "Cure.hpp"

#include "ICharacter.hpp"
#include "Character.hpp"

/* Constructors ============================================================= */
Cure::Cure(void) : AMateria()
{
	this->_type = "cure";
	return;
}

Cure::Cure(const Cure &cure) : AMateria(cure)
{
	this->_type = cure._type;
	return;
}

Cure::Cure(const std::string & type) : AMateria(type)
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
	this->_type = cure._type;
	return (*this);
}

/* Member functions ========================================================= */
std::string const &	Cure::getType(void) const
{
	return (this->_type);
}

AMateria	*Cure::clone(void) const
{
	return (new Cure);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return;
}
