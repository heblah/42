/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:36:31 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/08 14:28:14 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

class ScalarConverter 
{
    public:
                                ScalarConverter(void);
                                ScalarConverter(const ScalarConverter & sc);
                                ScalarConverter(const double d);
                                ~ScalarConverter(void);

        const ScalarConverter & operator=(const ScalarConverter & sc);

                                operator char   (void) const;
                                operator int    (void) const;
                                operator float  (void) const;
                                operator double (void) const;

       void                     setDouble(double d);
       double                   getDouble(void) const;

    private:
        double                  _d;
};

std::ostream &  operator<<(std::ostream &os, const ScalarConverter & sc);

#endif /* SCALARCONVERTER_HPP */
