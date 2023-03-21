/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:05:36 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/21 14:41:56 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>

class BitcoinExchange
{
	public:
		typedef std::map<std::string, float> bcMap;

								BitcoinExchange(void);
								BitcoinExchange(const BitcoinExchange & bc);
								~BitcoinExchange(void);

		const BitcoinExchange &	operator=(const BitcoinExchange & bc);

		const bcMap &			getDataBase(void) const;
		const float &			find(const std::string & key) const;
		void					addData(const std::string & str);

		class badInput : public std::exception {
			const char *	what(void) const throw() {
				return ("Error: bad input => ");
			}
		};

		class IntegerOverflow : public std::exception {
			const char *	what(void) const throw() {
				return ("Error: too large number.");
			}
		};

		class NegativNumber : public std::exception {
			const char *	what(void) const throw() {
				return ("Error: not a positiv number.");
			}
		};

	private:
		bcMap					_db;

};

std::ostream &	operator<<(std::ostream & ofs, const BitcoinExchange & bc);

#endif /* BITCOINEXCHANGE_HPP */
