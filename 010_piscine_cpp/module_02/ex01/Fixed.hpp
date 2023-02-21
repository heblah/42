/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:44:06 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/21 09:44:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

	public:
				Fixed(void);
				~Fixed(void);

				Fixed(const Fixed& nb);
				Fixed(int const nb);
				Fixed(float const nb);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed	*operator=(Fixed const &val);

	private:
		int					_n;
		static const int	_bits;

};

std::ostream	&operator<<(std::ostream &os, Fixed const &nb);

#endif
