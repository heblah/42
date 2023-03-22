/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:25:19 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/22 10:21:02 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

class RPN
{
	public:
								RPN(void);
								RPN(const RPN & rpn);
								~RPN(void);

		const RPN &				operator=(const RPN &rpn);

		const std::stack<char>	getStack(void) const;
		const bool &			getFlag(void) const;
		void					push(const char & c);
		void					pop(void);
		const std::string &		top(void);
		const int				op(void);

		class WrongCharacter : public std::exception {
			public:
				const char *	what(void) const throw() {
					return ("Error: wrong character.");
				}
		};

	private:
		std::stack<char>		_stack;
		bool					_badChar;

};

#endif /* RPN_HPP */
