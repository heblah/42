/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:12:43 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/08 18:18:36 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP 

class Base
{
    public:
        virtual ~Base(void){}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif /* BASE_HPP */
