/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:44:06 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/21 16:28:46 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

	public:
				Fixed(void);
				Fixed(const Fixed& nb);
				Fixed(int const nb);
				Fixed(float const nb);

				~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(Fixed const &a, Fixed const &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(Fixed const &a, Fixed const &b);

		void	operator=(Fixed const &fixed);
		bool	operator<(Fixed const &cmp) const;
		bool	operator>(Fixed const &cmp) const;
		bool	operator<=(Fixed const &cmp) const;
		bool	operator>=(Fixed const &cmp) const;
		bool	operator==(Fixed const &cmp) const;
		bool	operator!=(Fixed const &cmp) const;
		Fixed	operator+(Fixed const &a) const;
		Fixed	operator-(Fixed const &a) const;
		Fixed	operator*(Fixed const &a) const;
		Fixed	operator/(Fixed const &a) const;
		Fixed	operator++(int); //post increment
		Fixed	operator++(void); //pre increment
		Fixed	operator--(int); //post decrement
		Fixed	operator--(void); //pre decrement
	private:
		int					_n;
		static const int	_bits;

};

std::ostream	&operator<<(std::ostream &os, Fixed const &nb);

#endif
