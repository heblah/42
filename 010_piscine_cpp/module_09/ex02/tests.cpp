/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:10:43 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/24 10:06:56 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <deque>

int	main(void)
{
	void				*ct __attribute__((unused));
	std::vector<int>	*p __attribute__((unused));
	int					flag = 1;

	if ( flag == 1)
		ct = new std::vector<int>;
	else
		ct = new std::deque<int>;
	p = static_cast< std::vector<int>* >(ct);
	return (0);
}
