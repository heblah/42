/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:03:35 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/09 18:08:25 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP 

template<typename T>
class Array
{
	public:
						Array(void);
						Array(const Array & array);
						Array(const unsigned int n);
						~Array(void);

		Array<T>	&	operator=(const Array<T> & array);
		T			&	operator[](const unsigned int i);

		unsigned int	getSize(void) const;
		void			setSize(const unsigned int i);

		class InvalidIndex : public std::exception
		{
			const char *	what(void) const throw();
		};

	private:
		T*				_array;
		unsigned int	_size;

};

#include "Array.tpp"

#endif /* ARRAY_HPP */
