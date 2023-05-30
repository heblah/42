/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:48:31 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/21 16:48:55 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP 

#include <stdint.h>

typedef struct s_data
{
	int		a;
	int		b;
	char	c;
	void 	*p;
}			Data;

class Serializer
{
    public:
        				Serializer(void *ptr);
						~Serializer(void);

        Serializer &    operator=(const Serializer & s);

        static uintptr_t       serialize(Data* ptr);
        static Data *          deserialize(uintptr_t raw);

    private:
        static void *	_p;

                		Serializer(void);
                        Serializer(const Serializer &s);
		static void		_setP( void * ptr );
};

#endif /* SERIALIZER_HPP */
