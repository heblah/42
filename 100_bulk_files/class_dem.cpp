/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_dem.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/08 18:50:38 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Base {

public:
            Base(void) { this->_p = 147;}
    virtual ~Base(void) {}

    virtual int get() {return this->_p;}
private:
    int _p;

};

class Derived : public Base {
    public:
        Derived(void) : Base() {this->_p = 256;}
        ~Derived(void){}

    int get() {
        std::cout << this->Base::get();
        return this->_p;}
    private:
        int _p;
};

int main(void)
{
    Derived d;

    std::cout << d.get() << std::endl;
   
   // std::cout << d.Base::get() << std::endl;
    return 0;
}
