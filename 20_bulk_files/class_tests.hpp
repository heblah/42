/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_tests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/08 18:45:20 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
 #define CLASS_HPP

class Base {

public:
    Base(void) { this->_p = 147;}
    ~Base(void) {}

private:
    int _p;

};

class Derived : public {
    public:
        Derived(void) : Base() {this->_p = 256;}

    private:
        int _p;
};

#endif
