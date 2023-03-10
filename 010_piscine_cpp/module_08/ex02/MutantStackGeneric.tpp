/* ========================================================================== */
/* Template : generic ======================================================= */
/*    for vector, deque, set and map ======================================== */
/* ========================================================================== */

#ifndef MUTANTSTACKGENERIC_TPP
#define MUTANTSTACKGENERIC_TPP

//#include "MutantStack.hpp"

// Constructors ============================================================= //
template <typename Base, typename T>
MutantStack<Base, T>::MutantStack(void)
{
	if (PRINT)
		std::cout << "Default constructor from generic template" << std::endl;
	return;
}

template <typename Base, typename T>
MutantStack<Base, T>::MutantStack(const MutantStack & ms) : _container(ms._container)
{
	if (PRINT)
		std::cout << "Copy constructor from generic template" << std::endl;
	return;
}

// Destructor =============================================================== //
template <typename Base, typename T>
MutantStack<Base, T>::~MutantStack(void)
{
	if (PRINT)
		std::cout << "Destructor from generic template" << std::endl;
	return;
}

// Operators ================================================================ //
template <typename Base, typename T>
const MutantStack<Base, T> &	MutantStack<Base, T>::operator=(const MutantStack & ms)
{
	ConstBaseRef			source	= ms.getContainer();
	typename Base::iterator	it		= source.begin();
	int						pos		= 0;

	this->_container.clear();
	while (it != source.end())
	{
		this->_container.insert( *it, pos);
		it++;
		pos++;
	}
	return (*this);
}

// Member funtions ========================================================== //
template <typename Base, typename T>
typename Base::const_reference	MutantStack<Base, T>::getContainer(void) const
{
	return (this->_container);
}

template <typename Base, typename T>
void	MutantStack<Base, T>::addElement(const T & elem)
{
	this->_container.insert( elem, 0 );
	return;
}
#endif
