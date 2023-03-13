/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_dem.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/13 12:31:59 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Base {

	public:
		virtual ~Base(void) {}

		virtual int get() = 0 ;
	/*
	private:
		int _p;
	*/

};

class Derived1 : public Base {
    public:
        Derived1(void) : Base() {this->_p = 147;}
        ~Derived1(void){}

    virtual int get() {
        //std::cout << this->Base::get();
        return this->_p;}
    private:
        int _p;
};

class Derived2 : public Base {
    public:
        Derived2(void) : Base() {this->_p = 42;}
        ~Derived2(void){}

    virtual int get() {
        //std::cout << this->Base::get();
        return this->_p;}
    private:
        int _p;
};

class DeDerived : public Derived1, public Derived2 {
    public:
        DeDerived(void) : Derived1(), Derived2() {this->_p = 666;}
        ~DeDerived(void){}

    int get() {
        //std::cout << this->Base::get();
        return this->_p;}
    private:
        int _p;
};

int main(void)
{
    Derived1	d1;
    Derived2	d2;
    DeDerived	dd1;
	Base		*ptr __attribute__((unused)) = &d1;

    std::cout << "Derived1 _p  = " << d1.get() << std::endl;
    std::cout << "Derived2 _p  = " << d2.get() << std::endl;

    std::cout << "Dederived _p = " << dd1./*Derived2::*/get() << std::endl;
    std::cout << "Dederived* _p = " << ptr->get() << std::endl;
   
   // std::cout << d.Base::get() << std::endl;
    return 0;
}
