/* ========================================================================== */
/* Template : generic ======================================================= */
/* ========================================================================== */

#ifndef MUTANTSTACKGENERIC_TPP
#define MUTANTSTACKGENERIC_TPP

#include "MutantStack.hpp"

// Constructors ============================================================= //
template <typename Base>
MutantStack<Base>::MutantStack(void)
{
	if (PRINT)
		std::cout << "Default constructor from generic template" << std::endl;
	return;
}

template <typename Base>
MutantStack<Base>::MutantStack(const MutantStack & ms) : _container(ms._container)
{
	if (PRINT)
		std::cout << "Copy constructor from generic template" << std::endl;
	return;
}

// Destructor =============================================================== //
template <typename Base>
MutantStack<Base>::~MutantStack(void)
{
	if (PRINT)
		std::cout << "Destructor from generic template" << std::endl;
	return;
}

// Operators ================================================================ //
template <typename Base>
const MutantStack<Base> &	MutantStack<Base>::operator=(const MutantStack & ms)
{
	ConstBaseRef			source	= ms.getContainer();
	typename Base::iterator	it		= source.begin();

	this->_container.clear();
	while (it != source.end())
	{
		this->_container.insert( *it );
		it++;
	}
	return (*this);
}

// Member funtions ========================================================== //
template <typename Base>
typename Base::const_reference	MutantStack<Base>::getContainer(void) const
{
	return (this->_container);
}

#endif
