/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:34:58 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/09 18:20:48 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
 #define PHONEBOOK_HPP

class PhoneBook{

	public:
		PhoneBook(void);
		~PhoneBook(void);

	private:
		Contact		contact[8];
		uint8_t		n;

		void	_add(void);
		void	_search(void) const;
		void	_exit(void);

};

#endif
