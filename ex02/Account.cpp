#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int        Account::_nbAccounts = 0;
int        Account::_totalAmount = 0;
int        Account::_totalNbDeposits = 0;
int        Account::_totalNbWithdrawals = 0;

Account::Account() {
    this->_accountIndex = Account::_nbAccounts++;
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount 
        << ";created" << std::endl;
}

Account::Account(int initial_deposit) {
    this->_accountIndex = Account::_nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount 
        << ";created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount 
        << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:"
        << this->_amount << ";deposit:" << deposit;
    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    std::cout << ";amount:" << this->_amount << ";nb_deposits:"
        << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" 
        << this->checkAmount() << ";";
    if (withdrawal > this->checkAmount()) {
        std::cout << "withdrawal refused" << std::endl;
        return false;
    }
    std::cout << "withdrawal:" << withdrawal;
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;
    std::cout << ";amount:" << this->_amount << ";nb_withdrawals:"
        << this->_nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount() const {
    return this->_amount;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
        << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
        << std::endl;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount
        << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals
        << std::endl;
}

void Account::_displayTimestamp() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    std::cout << "[" << (now->tm_year + 1900) 
              << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << now->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec << "] ";
}