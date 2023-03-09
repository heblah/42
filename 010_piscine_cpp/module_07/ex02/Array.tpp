/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:08:52 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/09 13:27:56 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Constructors ============================================================= */
template<typename T>
Array<T>::Array(void)
		: _array( NULL ), _size( 0 )
{
	return;
}

template<typename T>
Array<T>::Array(const Array & array)
		: _array( new T[array.getSize()] ), _size( array.getSize() )
{
	unsigned int	i = 0;

	while ( i < this->_size )
	{
		this->_array[i] = array[i];
		i++;
	}
	return;
}

template<typename T>
Array<T>::Array(const unsigned int n)
		: _array( new T[n]() ), _size( n )
{
	return;
}

/* Desctructor ============================================================== */
template<typename T>
Array<T>::~Array(void)
{
	delete[] this->_array;
	return;
}

/* Operators ================================================================ */
template<typename T>
const Array<T> &	Array<T>::operator=(const Array<T> & array)
{
	unsigned int	i = 0;

	this->setSize( array.getSize() );

	if (this->array != NULL)
		delete[] this->_array;
	this->_array = new T[ array.getSize() ]();

	while (i < this->_size)
	{
		*(this->_array + i) = array[i];
		i++;
	}
	return ( *this );
}

template<typename T>
T & 	Array<T>::operator[](const unsigned int i)
{
	try
	{
		if (i >= this->_size)
			throw InvalidIndex();
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return ( *(this->_array + i) );
}

/* Member functions ========================================================= */
template<typename T>
unsigned int	Array<T>::getSize(void) const
{
	return ( this->_size );
}

template<typename T>
void	Array<T>::setSize(const unsigned int n)
{
	this->_size = n;
	return;
}

/* Exceptions =============================================================== */
template<typename T>
const char *	Array<T>::InvalidIndex::what(void) const throw()
{
	return ( "Error: index is out of range" );
}
