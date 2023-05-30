/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:18:42 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/17 13:38:52 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

#include "Classes.hpp"

Base *  generate(void)
{
    int i = rand() % 9;

    if (i < 3)
        return (new A);
    else if (i < 6)
        return (new B);
    else if (i < 9)
        return (new C);
    return (NULL);
}

void    identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "The class pointed is A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "The class pointed is B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "The class pointed is c" << std::endl;
    else
        std::cout << "It's NULL pointer" << std::endl;
    return;
}

void    identify(Base & p)
{
    try {
        A a __attribute__((unused)) = dynamic_cast<A &>(p);
        std::cout << "The class referenced is A" << std::endl;
    }
    catch(std::exception & e)
    {
        try {
            B b __attribute__((unused)) = dynamic_cast<B &>(p);
            std::cout << "The class referenced is B" << std::endl;
        }
        catch(std::exception &e)
        {
            try {
                C c __attribute__((unused)) = dynamic_cast<C &>(p);
                std::cout << "The class referenced is C" << std::endl;
            }
            catch (std::exception & e)
            {
                std::cerr << "The class referenced in not A, B or C" << std::endl;
            }
        }
    }
    return;
}

int main(void)
{
    Base    *ptr	= NULL;
    int     n 		= 5;
	srand( time(NULL) );

    std::cout << "========== void identify(Base* p) ==========" << std::endl;
    n = 5;
    while (n-- > 0)
    {
        ptr = generate();
        identify(ptr);
        delete ptr;
    }

    std::cout << std::endl;
    std::cout << "========== void identify(Base& p) ==========" << std::endl;
    n = 5;
    while (n-- > 0)
    {
        ptr = generate();
        identify(*ptr);
        delete ptr;
    }
    return (0);
}
