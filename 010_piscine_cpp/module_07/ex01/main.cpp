/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:32:25 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/23 16:17:01 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "iter.hpp"

void	increment(const int & elem)
{
	const_cast<int&>(elem)++;
	return;
}

void	puttab(int *tab, size_t size)
{
	size_t i = 0;

	while (i < size)
	{
		std::cout << tab[i++];
		std::cout << ( i != size ? ", " : ""  );
	}
	std::cout << std::endl;
	return;
}

int	main(void)
{
	int	tab[] = {0, 2, 4, 6, 8, 10};

	std::cout << "========== Initial array ==========" << std::endl;
	puttab(tab, 6);

	std::cout << "========== Array after iter =======" << std::endl;
	::iter<int>(tab, 6, &increment);
	puttab(tab, 6);
	return (0);
}

/*
class Awesome{

public:
    Awesome(void) : _n(42) { return; }

    int get_n() const {return this->_n;}

private:
    int _n;
};

std::ostream &operator << (std::ostream &o, const Awesome & rhs){o << rhs.get_n(); return o;}
template<typename T>
void print( T const & x ) { std::cout << x << std::endl; return; }

int main(void)
{
	int		tab[] = {0, 1, 2, 3, 4};
	Awesome	tab2[5];

	iter(tab, 5, &print);
	iter(tab2, 5, &print);
    return 0;
}
*/
