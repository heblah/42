/* ========================================================================== */
/* Template : MutantStack =================================================== */
/* ========================================================================== */

#ifndef MUTANTSTACKGENERIC_TPP
#define MUTANTSTACKGENERIC_TPP

// Constructors ============================================================= //
template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
	if (PRINT)
		std::cout << "Default constructor from generic template" << std::endl;
	return;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack & ms) : std::stack<T>( ms )
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
MutantStack<T> &	MutantStack<T>::operator=( const MutantStack & ms )
{
	while ( this->size() != 0 )
		this->pop();
	this->c = ms.c;
	return (*this);
}

// Member funtions ========================================================== //
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return ( this->c.begin() );
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return ( this->c.end() );
}

template <typename T>
typename MutantStack<T>::r_iterator	MutantStack<T>::rbegin(void)
{
	return ( this->c.rbegin() );
}

template <typename T>
typename MutantStack<T>::r_iterator	MutantStack<T>::rend(void)
{
	return ( this->c.rend() );
}

/*
template <typename T>
typename MutantStack<T>::ConstStackRef 	MutantStack<T>::getStack(void) const
{
	return (this->_container);
}

template <typename T>
void	MutantStack<T>::push(const T & elem)
{
	this->_stack.push( elem );
	return;
}

template <typename T>
void	MutantStack<T>::pop(void)
{
	this->_stack.pop();
	return;
}

template <typename T>
T &	MutantStack<T>::top(void)
{
	return ( this->_stack.top() );
}

*/
#endif
