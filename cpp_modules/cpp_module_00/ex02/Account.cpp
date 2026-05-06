/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:21:02 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/23 14:40:26 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void    Account::_displayTimestamp(void)
{
    time_t  t = time(NULL);

    std::cout << std::setfill('0') << "[" << 1900 + localtime(&t)->tm_year << std::setw(2) << 1 + localtime(&t)->tm_mon << std::setw(2) << localtime(&t)->tm_mday << "_" << std::setw(2) << localtime(&t)->tm_hour << std::setw(2) << localtime(&t)->tm_min << std::setw(2) << localtime(&t)->tm_sec << "] ";
}

Account::Account(int initial_desposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_desposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
    _nbAccounts++;
    _totalAmount += initial_desposit;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void    Account::makeDeposit(int deposit)
{
    _nbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits << "\n";
    _totalAmount += deposit;
    _totalNbDeposits++;
    _amount += deposit;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    if (_amount - withdrawal < 0)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused\n";
        return (false);
    }
    _nbWithdrawals++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << "\n";
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    return (true);
}

int    Account::checkAmount(void) const
{
    return (_amount);
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";   
}

int     Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int     Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int     Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int     Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << "\n"; 
}