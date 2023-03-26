/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:05:36 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/26 18:28:14 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>

class BitcoinExchange
{
	public:
		typedef std::map<int, float> bcMap;

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
				return ("Error: too large number. ");
			}
		};

		class NegativNumber : public std::exception {
			const char *	what(void) const throw() {
				return ("Error: not a positiv number. ");
			}
		};

	private:
		bcMap					_db;
		bool					_error;
		int						_str2int(std::string str) const;

};

std::ostream &	operator<<(std::ostream & ofs, const BitcoinExchange & bc);

#endif /* BITCOINEXCHANGE_HPP */
