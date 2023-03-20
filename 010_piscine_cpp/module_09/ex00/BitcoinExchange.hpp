/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:05:36 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/20 09:57:43 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <vector>

class BitcoinExchange
{
	public:
									BitcoinExchange(void);
									BitcoinExchange(const BitcoinExchange &bc);
									BitcoinExchange(std::ifstream & is);
									~BitcoinExchange(void);

		const BitcoinExchange &		operator=(const BitcoinExchange &be);

		void						putDataBase(void) const;
		std::vector<std::string> &	getDataBase(void) const;
		void						setDataBase(std::ifstream & is);

	private:
		std::vector<std::string>	_db;
};

#endif /* BITCOINEXCHANGE_HPP */
