/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:21:04 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/23 15:58:17 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "whatever.hpp"

int	main(void)
{
	int	x = 147;
	int	y = 90;

	std::cout << "=========== tests on int ============" << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "min = " << ::min<int>( x, y ) << std::endl;
	std::cout << "max = " << ::max<int>( x, y ) << std::endl;
	::swap<int>( x, y );
	std::cout << "x = " << x << ", y = " << y << std::endl;

	std::cout << "========== tests on string ==========" << std::endl;
	std::string	str1 = "smoke weed";
	std::string	str2 = "drink water";

	std::cout << "str1 = " << str1 << ", str2 = " << str2 << std::endl;
	std::cout << "min = " << ::min<std::string>( str1, str2 ) << std::endl;
	std::cout << "max = " << ::max<std::string>( str1, str2 ) << std::endl;
	::swap<std::string>( str1, str2 );
	std::cout << "str1 = " << str1 << ", str2 = " << str2 << std::endl;

	return (0);
}

/*
class Awesome{

public:
    Awesome(void) : _n(0){}
    Awesome(int n) : _n(n) {}

    Awesome &operator= (Awesome &a) {_n = a._n; return *this;}

    bool operator==	(const Awesome & rhs) const {return (this->_n ==	rhs._n);}
    bool operator!=	(const Awesome & rhs) const {return (this->_n !=	rhs._n);}
    bool operator>	(const Awesome & rhs) const {return (this->_n >	rhs._n);}
    bool operator<	(const Awesome & rhs) const {return (this->_n <	rhs._n);}
    bool operator>=	(const Awesome & rhs) const {return (this->_n >=	rhs._n);}
    bool operator<=	(const Awesome & rhs) const {return (this->_n <=	rhs._n);}

    int get_n()const {return _n;}

private:
    int _n;
};

std::ostream &operator << (std::ostream &o, const Awesome& a){o << a.get_n(); return o;}

int main()
{
    Awesome a(2), b(4);

    swap (a,b);
    std::cout << "a: " << a << " b: " << b << std::endl;
    std::cout << "max: " << max(a,b) << std::endl;
    std::cout << "min: " << min(a,b) << std::endl;
    return 0;
}
*/
