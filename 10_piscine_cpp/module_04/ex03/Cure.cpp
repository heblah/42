/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:23:46 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/31 12:06:17 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Character.hpp"
#include "Cure.hpp"

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
Cure	&Cure::operator=(const Cure &cure __attribute__((unused)))
{
	return (*(new Cure));
}

/* Member functions ========================================================= */
std::string const &	Cure::getType(void) const
{
	return (this->_type);
}

AMateria	*Cure::clone(void) const
{
	return (new Cure( this->_type ));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return;
}