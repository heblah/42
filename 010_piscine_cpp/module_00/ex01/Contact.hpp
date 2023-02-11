/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:01:22 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/11 14:19:29 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact{

	public:
		//Contact(void);
		//~Contact(void);

		std::string	getcontact(int i) const;
		void		setcontact(int i);
		void		displaycontact(void) const;

	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_number;
		std::string	_secret;

};
#endif
