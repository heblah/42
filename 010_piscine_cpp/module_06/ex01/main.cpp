/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:04:36 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/08 17:49:47 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Serializer.hpp"

int main(void)
{
    Data        data;
    uintptr_t   uptr;
    Data        *pdata;
    Serializer  s;

    uptr = s.serialize(&data);
    pdata = s.deserialize(uptr);

    std::cout << "&data       : " << &data << std::endl;
    std::cout << "uintptr_t   : " << "0x" << std::hex << uptr << std::endl;
    std::cout << "*pdata      : " << std::hex << pdata << std::endl;
    return (0);
}
