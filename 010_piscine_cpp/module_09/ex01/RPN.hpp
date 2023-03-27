/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:25:19 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/22 12:33:34 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class RPN
{
	public:
								RPN(void);
								RPN(const RPN & rpn);
								~RPN(void);

		RPN &					operator=(const RPN &rpn);

		int						op(const char * str);
		const std::stack<int> &	getStack(void) const;
		void					push(const char & c);
		void					pop(void);

		class WrongCharacter : public std::exception {
			public:
				const char *	what(void) const throw() {
					return ("Error: wrong character.");
				}
		};

		class ZeroDivision : public std::exception {
			public:
				const char *	what(void) const throw() {
					return ("Error: division per 0 is forbidden.");
				}
		};

	private:
		std::stack<int>		_stack;

};

#endif /* RPN_HPP */
