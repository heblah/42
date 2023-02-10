/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:34:58 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/10 11:58:18 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
 #define PHONEBOOK_HPP

class PhoneBook{

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void) const;
		void	exit(void);

	private:
		Contact		_contact[8];
		uint8_t		_index;
		
		void	_resume(void) const;

};

#endif
