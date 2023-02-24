/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:11:13 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/24 12:28:25 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Constructors ============================================================= */
Cat::Cat(void)
{
	std::cout << "Default Cat constructor called" << std::enl;
	return;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
	std::cout << "Copy Cat constructor called" << std::enl;
	//this->setType(cat.getType());
	return;
}

/* Destructor =============================================================== */
Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	return;
}

/* Operators ================================================================ */
Cat & Cat::operator=(const Cat &cat)
{
	this->setType(cat.getType());
	return (*this);
}

/* Member functions ========================================================= */
void	Cat::makeSound(void) const
{
	std::cout << "Cat's sound : Miaouss, oui la guerre !" << std::endl;
	return;
}
