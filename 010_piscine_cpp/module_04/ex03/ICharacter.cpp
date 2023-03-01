/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:33:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/01 09:35:55 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ICharacter.hpp"

/* Constructors ============================================================= */
ICharacter::ICharacter(void)
{
	return;
}

ICharacter::ICharacter(const ICharacter & character)
{
	int	idx = 0;

	this->_name = character._name;
	while(idx < 4)
	{
		inventory[idx] = new 
	}
	return;
}

/* Destructor =============================================================== */
ICharacter::~ICharacter(void)
{
	return;
}

/* Operators ================================================================ */
ICharacter &	ICharacter::operator=(const ICharacter & character)
{
	return (*this);
}

/* Member functions ========================================================= */
