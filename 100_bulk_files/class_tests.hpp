/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_tests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/10 10:23:30 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
 #define CLASS_HPP

class ft_classe{

public:
	std::string buf;

	ft_classe(void);
	~ft_classe(void);

private:
	void	foo(void) const;

};
#endif
