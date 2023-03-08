/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:58:05 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/08 17:30:22 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
//#include <cstdint>
#include <stdint.h>

#include "Serializer.hpp"

/* Constructors ============================================================= */
Serializer::Serializer(void)
{
    this->_p = NULL;
    return;
}

Serializer::Serializer(const Serializer &s)
{
    this->_p = s._p;
    return;
}

Serializer::Serializer(void *ptr)
{
    this->_p = ptr;
    return;
}

/* Destructor =============================================================== */
Serializer::~Serializer(void)
{
    return;
}

/* Operators ================================================================ */
const Serializer &  Serializer::operator=(const Serializer & s)
{
    this->_p = s._p;
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
