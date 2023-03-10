/* ========================================================================== */
/* Template : MutantStack =================================================== */
/* ========================================================================== */

#ifndef MUTANTSTACKGENERIC_TPP
#define MUTANTSTACKGENERIC_TPP

// Constructors ============================================================= //
template <typename T>
MutantStack<T>::MutantStack(void)
{
	if (PRINT)
		std::cout << "Default constructor from generic template" << std::endl;
	return;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack & ms) : _stack(ms._stack)
{
	if (PRINT)
		std::cout << "Copy constructor from generic template" << std::endl;
	return;
}

// Destructor =============================================================== //
template <typename T>
MutantStack<T>::~MutantStack(void)
{
	if (PRINT)
		std::cout << "Destructor from generic template" << std::endl;
	return;
}

// Operators ================================================================ //
template <typename T>
const MutantStack<T> &	MutantStack<T>::operator=(const MutantStack & ms __attribute__((unused)))
{
	T	tmp;

	while (this->_stack.size() != 0)
		tmp = this->_stack.pop();
	return (*this);
}

// Member funtions ========================================================== //
template <typename T>
typename std::stack<T>::const_reference 	MutantStack<T>::getStack(void) const
{
	return (this->_container);
}

/*
template <typename T>
void	MutantStack<T>::push(const T & elem)
{
	this->_container.insert( elem, 0 );
	return;
}
*/
#endif
