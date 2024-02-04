/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:08:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/09 21:23:29 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP 

#include <set>

class Span
{
	public:
								Span(void);
								Span(const Span & span);
								Span(const unsigned int maxsize);
								~Span(void);

		Span &					operator=(const Span & span);

		unsigned int			getMaxSize(void) const;
		const std::set<int> &	getSet(void) const;

		void					addNumber(const int n);
		unsigned int			shortestSpan(void) const;
		unsigned int			longestSpan(void) const;
		void					fillSpan(void);

		class InsufficientSize : public std::exception {
			const char *	what(void) const throw();
		};
		class SpanIsFull : public std::exception {
			const char *	what(void) const throw();
		};

	private:
		unsigned int	_maxsize;
		std::set<int>	_set;

};

#endif /* SPAN_HPP */