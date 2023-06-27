/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:36:34 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/24 18:51:11 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain {
	public:
						Brain(void);
						Brain(const Brain &brain);
						Brain(const std::string brain[]);
						~Brain(void);

		Brain &			operator=(const Brain &brain);

		unsigned int	getQi(void) const;
		std::string		getIdea(size_t pos) const;
		void			setIdea(const std::string idea, size_t pos);
	private:
		std::string					_brain[100];
		static const unsigned int	_qi;
};

#endif
