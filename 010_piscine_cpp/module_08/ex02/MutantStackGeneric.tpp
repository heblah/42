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
const MutantStack<T> &	MutantStack<T>::operator=(const MutantStack & ms)
{
	while ( this->_stack.size() != 0 )
		this->_stack.pop();
	this->_stack = ms._stack;
	return (*this);
}

// Member funtions ========================================================== //
template <typename T>
typename std::stack<T>::const_reference 	MutantStack<T>::getStack(void) const
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

// Iterator nested class ==================================================== //
template <typename T>
MutantStack<T>::Iterator::Iterator(void)
{
	if (PRINT)
		std::cout << "Default MutantStack::Iterator constructor" << std::endl;
	return;
}

template <typename T>
MutantStack<T>::Iterator::Iterator(const Iterator & it __attribute__((unused)))
{
	if (PRINT)
		std::cout << "Copy MutantStack::Iterator constructor" << std::endl;
	return;
}

template <typename T>
MutantStack<T>::Iterator::~Iterator(void)
{
	if (PRINT)
		std::cout << "MutantStack::Iterator tructor" << std::endl;
}

#endif
