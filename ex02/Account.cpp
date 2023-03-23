#include "Account.hpp"
#include <iostream>
#include <ctime>

// Definition part of class static variables
int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

// These functions are never used in tests.cpp
int	Account::getNbAccounts( void ) { return _nbAccounts ; }
int	Account::getTotalAmount( void ) { return _totalAmount ; }
int	Account::getNbDeposits( void ) { return _totalNbDeposits ; }
int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals ; }

void	Account::displayAccountsInfos( void )
{
	//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
	Account::_displayTimestamp() ;
	std::cout
		<< "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals
		<< "\n" ;
}

void	Account::_displayTimestamp( void )
{
	//[19920104_091532] 
	const char *format = "%Y%m%d_%H%M%S" ;
	std::time_t t = std::time(0) ;
	char cstr[128] ;
	std::strftime( cstr, sizeof(cstr), format, std::localtime(&t) ) ;
	std::cout << "[" << cstr << "] " ;
}

Account::Account( int initial_deposit ):
	_accountIndex(_nbAccounts++),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	//[19920104_091532] index:0;amount:42;created
	_totalAmount += _amount ;
	Account::_displayTimestamp() ;
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created\n" ;
}

Account::Account(void):
	_accountIndex(_nbAccounts++),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	//[19920104_091532] index:0;amount:42;created
	Account::_displayTimestamp() ;
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created\n" ;
}

Account::~Account( void ) {
	//[19920104_091532] index:0;amount:47;closed
	_nbAccounts-- ;
	_totalAmount -= _amount ;
	Account::_displayTimestamp() ;
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed"
		<< "\n" ;
}

void	Account::makeDeposit( int deposit ) {
	//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	_nbDeposits++ ;
	_totalNbDeposits++ ;
	_amount += deposit ;
	_totalAmount += deposit ;
	Account::_displayTimestamp() ;
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount - deposit << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << _amount << ";"
		<< "nb_deposits:" << _nbDeposits
		<< "\n" ;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	if ( withdrawal <= _amount ) {
		_amount -= withdrawal ;
		_totalAmount -= withdrawal ;
		_nbWithdrawals++ ;
		_totalNbWithdrawals++ ;
		// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
		Account::_displayTimestamp() ;
		std::cout
			<< "index:" << _accountIndex << ";"
			<< "p_amount:" << _amount + withdrawal << ";"
			<< "withdrawal:" << withdrawal << ";"
			<< "amount:" << _amount << ";"
			<< "nb_withdrawals:" << _nbWithdrawals
			<< "\n" ;
		return true ;
	}
	// [19920104_091532] index:5;p_amount:23;withdrawal:refused
	Account::_displayTimestamp() ;
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";"
		<< "withdrawal:refused"
		<< "\n" ;
	return false ;
}

// This function is never used in tests.cpp, why exist?
int		Account::checkAmount( void ) const
{
	return _amount ;
}

void	Account::displayStatus( void ) const
{
	//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
	Account::_displayTimestamp() ;
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals
		<< "\n" ;
}
