/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:33:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/02 11:28:31 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
//#include "ICharacter.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

/* Constructors ============================================================= */
Character::Character(void)
{
	int	idx = 0;

	while (idx < 4)
	{
		_inventory[idx] = NULL;
		idx++;
	}
	return;
}

Character::Character(const Character & character)
{
	int	idx = 0;

	this->_name = character.getName();
	while(idx < 4)
	{
		if (character._inventory[idx] != NULL && character._inventory[idx]->getType().compare("ice") == 0)
		{
			if (this->_inventory[idx] != NULL)
				delete this->_inventory[idx];
			this->_inventory[idx] = new Ice;
		}
		else if (character._inventory[idx] != NULL && character._inventory[idx]->getType().compare("cure") == 0)
		{
			if (this->_inventory[idx] != NULL)
				delete this->_inventory[idx];
			this->_inventory[idx] = new Cure;
		}
		else if (character._inventory[idx] == NULL)
		{
			if (this->_inventory[idx] != NULL)
				delete this->_inventory[idx];
			this->_inventory[idx] = NULL;
		}
		idx++;
	}
	return;
}

Character::Character(const std::string &name) : _name(name)
{
	int	idx = 0;

	while (idx < 4)
	{
		_inventory[idx] = NULL;
		idx++;
	}
	return;
}

/* Destructor =============================================================== */
Character::~Character(void)
{
	int	idx = 0;

	while (idx < 4)
	{
		if (this->_inventory[idx] != NULL)
		{
			delete this->_inventory[idx];
			this->_inventory[idx] = NULL;
		}
		idx++;
	}
	return;
}

/* Operators ================================================================ */
Character &	Character::operator=(const Character & character)
{
	int	idx = 0;

	this->_name = character.getName();
	while(idx < 4)
	{
		if (character._inventory[idx] != NULL && character._inventory[idx]->getType().compare("ice") == 0)
		{
			if (this->_inventory[idx] != NULL)
				delete this->_inventory[idx];
			this->_inventory[idx] = new Ice;
		}
		else if (character._inventory[idx] != NULL && character._inventory[idx]->getType().compare("cure") == 0)
		{
			if (this->_inventory[idx] != NULL)
				delete this->_inventory[idx];
			this->_inventory[idx] = new Cure;
		}
		else if (character._inventory[idx] == NULL)
		{
			if (this->_inventory[idx] != NULL)
				delete this->_inventory[idx];
			this->_inventory[idx] = NULL;
		}
		idx++;
	}
	return (*this);
}

/* Member functions ========================================================= */
std::string const &	Character::getName(void) const
{
	return (this->_name);
}

void	Character::setName(const std::string & name)
{
	this->_name = name;
	return;
}

void	Character::equip(AMateria *m)
{
	int	idx = 0;

	while (idx < 4)
	{
		if (this->_inventory[idx] == NULL)
		{
			this->_inventory[idx] = m;
			return;
		}
		idx++;
	}
	return;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->_inventory[idx] = NULL;
	return;
}

/*
void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
		this->_inventory[idx]->AMateria::use(target);
	return;
}
*/
