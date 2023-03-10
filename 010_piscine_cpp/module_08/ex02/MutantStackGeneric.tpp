/* ========================================================================== */
/* Template : generic ======================================================= */
/* ========================================================================== */

#ifndef MUTANTSTACKGENERIC_TPP
#define MUTANTSTACKGENERIC_TPP

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
#endif
