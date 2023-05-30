/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:44:06 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/27 12:28:02 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

	public:
				Fixed(void);
				Fixed(const Fixed& number);
				~Fixed(void);

		Fixed &	operator=(const Fixed & fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_n;
		static const int	_bits;

};

#endif
