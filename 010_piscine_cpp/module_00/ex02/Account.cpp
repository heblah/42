/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:37:57 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/12 16:39:04 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostrem>
#include <string>
#include "Account.hpp"

/*
	Public functions
*/
static int	getNbAccounts( void )
{
}

static int	getTotalAmount( void )
{
}

static int	getNbDeposits( void )
{
}

static int	getNbWithdrawals( void )
{
}

static void	displayAccountsInfos( void )
{
}

	//Constructor & destructor
Account( int initial_deposit )
{
	Account::_nbAccounts += 1;
}

~Account( void )
{
	Account::_nbAccounts -= 1;
}

	//Operations
void	makeDeposit( int deposit )
{
}

bool	makeWithdrawal( int withdrawal )
{
}

int		checkAmount( void ) const
{
}

void	displayStatus( void ) const
{
}



/*
	Private functions
*/
static void	_displayTimestamp( void )
{
	std::cout << "[";
}
