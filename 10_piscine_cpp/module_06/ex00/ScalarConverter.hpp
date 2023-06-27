/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:36:31 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/21 16:49:55 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

class ScalarConverter 
{
    public:
                            ScalarConverter(const double d);
                            ~ScalarConverter(void);

        ScalarConverter &   operator=(const ScalarConverter & sc);

                            operator char   (void) const;
                            operator int    (void) const;
                            operator float  (void) const;
                            operator double (void) const;

       static void			setDouble(double d);
       static double		getDouble(void);

    private:
        static double		_d;
                            ScalarConverter(void);
                            ScalarConverter(const ScalarConverter & sc);
};

std::ostream &  operator<<(std::ostream &os, const ScalarConverter & sc);

#endif /* SCALARCONVERTER_HPP */
