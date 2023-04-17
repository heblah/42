/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:48:31 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/17 15:24:30 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP 

//#include <cstdint>
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
                        Serializer(const Serializer &s);
                        Serializer(void *ptr);
                        ~Serializer(void);

        Serializer &    operator=(const Serializer & s);

        uintptr_t       serialize(Data* ptr);
        Data *          deserialize(uintptr_t raw);

    private:
        void *          _p;

                        Serializer(void);
};

#endif /* SERIALIZER_HPP */
