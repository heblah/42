/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:44:06 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/20 09:57:10 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

	public:
			Fixed(void);
			~Fixed(void);

			Fixed(const Fixed& number);

		int	getRawBits(void) const;
		int	setRawBits(int const raw);

	private:
		int					_n;
		static const int	_bits;

};

#endif
