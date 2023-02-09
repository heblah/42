/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:01:22 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/09 18:19:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
 #define CONTACT_HPP

class Contact{

	public:
		Contact(void);
		~Contact(void);

	private:
		string	_firstname;
		string	_lastname;
		string	_nickname;
		string	_number;
		string	_secret;

};
#endif
