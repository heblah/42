/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:58:05 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/21 16:48:25 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdint.h>

#include "Serializer.hpp"

void *	Serializer::_p = NULL;

/* Constructors ============================================================= */
Serializer::Serializer(void)
{
    return;
}

Serializer::Serializer(const Serializer & s __attribute__((unused)))
{
    return;
}

Serializer::Serializer(void *ptr)
{
	this->_setP( ptr );
    return;
}

/* Destructor =============================================================== */
Serializer::~Serializer(void)
{
    return;
}

/* Operators ================================================================ */
Serializer &  Serializer::operator=(const Serializer & s __attribute__((unused)))
{
    return (*this);
}

/* Member functions ========================================================= */
Data *  Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

uintptr_t   Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

void	Serializer::_setP(void * ptr)
{
	_p = ptr;
	return;
}
