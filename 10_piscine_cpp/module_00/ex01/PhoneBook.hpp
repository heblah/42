/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:34:58 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/14 17:14:25 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook{

	public:
		PhoneBook(void);

		void	add(void);
		void	search(void) const;

	private:
		Contact	_contact[8];
		int		_index;
		
		void	_resume(void) const;

};

#endif
