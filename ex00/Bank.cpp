//
// Created by Vinicius de Freitas Pereira on 20/09/26.
//

#include "Bank.hpp"
#include <type_traits>
#include <vector>
#include <iostream>

Bank::Bank()
{
    setLiquidity(0);
}

Bank::Bank(const int liquidity)
{
    setLiquidity(liquidity);
}

Bank::Bank(Bank const& rhs)
{
    *this = rhs;
}

Bank& Bank::operator=(Bank const& rhs)
{
    if (this != &rhs)
    {
        setLiquidity(rhs.getLiquidity());
        _clientAccounts = rhs.getClientAccounts();
    }
    return *this;
}


Bank::~Bank()
{
}

int Bank::getLiquidity() const
{
    return _liquidity;
}

std::vector<Account*> Bank::getClientAccounts() const
{
    return _clientAccounts;
}

void Bank::setLiquidity(int liquidity)
{
    _liquidity = liquidity;
}

void Bank::addClientAccount(Account* account)
{
    bool hasDuplicatedId = checkAccountId(account);
    if (hasDuplicatedId)
    {
        std::cout << "Account already exists with this id: " << account->getId() << "Account not registered in bank."<< std::endl;
        return;
    }
    
    _clientAccounts.push_back(account);

    if (account->getValue() > 0)
        this->depositFunds(account, account->getValue(), true);
}

Account* Bank::findAccount(Account* account)
{
    for (std::vector<Account*>::iterator it = _clientAccounts.begin();
         it != _clientAccounts.end();
         ++it)
    {
        if (*it == account)
        {
            return *it;
        }
    }

    return NULL;
}

bool Bank::checkAccountId(Account* account)
{
    for (std::vector<Account*>::iterator it = _clientAccounts.begin();
         it != _clientAccounts.end();
         ++it)
    {
        if ((*it)->getId() == account->getId())
            return true;
    }

    return false;
}

void Bank::removeClientAccount(Account* account)
{
    for (std::vector<Account*>::iterator it = _clientAccounts.begin();
         it != _clientAccounts.end();
         ++it)
    {
        if (*it == account)
        {
            _clientAccounts.erase(it);
            return;
        }
    }
}

void Bank::changeClientId(Account* account, int newId)
{
    Account* foundAccount = findAccount(account);
    foundAccount->setId(newId);
}

void Bank::changeAccountValue(Account* account, int newValue)
{
    account->setValue(newValue);
}

void Bank::checkFunds(Account* account)
{
    Account* foundAccount = findAccount(account);
    if (foundAccount)
        std::cout << "Account funds: " << foundAccount->getValue() << std::endl;
}

void Bank::withdrawFunds(Account* account, int amount)
{
    Account* foundAccount = findAccount(account);
    int currentValue = foundAccount->getValue();
    if (currentValue < amount)
    {
        std::cout << "Insufficient funds: " << currentValue << " < " << amount << std::endl;
        return;
    }
    
    foundAccount->setValue(currentValue - amount);
    std::cout << "Withdrawal successful: " << currentValue << " -> " << foundAccount->getValue() << std::endl;
}

void Bank::depositFunds(Account* account, int amount, bool firstDeposit)
{
    Account* foundAccount = findAccount(account);
    this->setLiquidity(this->getLiquidity() + (amount * 0.05));
    if (firstDeposit)
        changeAccountValue(account, amount * 0.95);
    else
        changeAccountValue(account, foundAccount->getValue() + (amount * 0.95));
    std::cout << "Deposit successful: " << amount << " -> " << foundAccount->getValue() << std::endl;
}

bool Bank::canLoanMoney(Account* account, int amount)
{
    int currentValue = account->getValue();
    return currentValue >= amount;
}

void Bank::loadMoney(Account* account, int amount)
{
    Account* foundAccount = findAccount(account);
    bool canLoan = canLoanMoney(account, amount);
    
    if (!canLoan)
    {
        std::cout << "Cannot loan money: " << amount << " > " << foundAccount->getValue() << std::endl;
        return;
    }
    
    foundAccount->setValue(foundAccount->getValue() + amount);
    std::cout << "Load successful: " << foundAccount->getValue() - amount << " -> " << foundAccount->getValue() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bank& bank)
{
    os << "Bank informations : " << std::endl;
    os << "Liquidity : " << bank.getLiquidity() << std::endl;
    std::vector<Account*> clientAccounts = bank.getClientAccounts();
    for (std::vector<Account*>::const_iterator it = clientAccounts.begin();
         it != clientAccounts.end();
         ++it)
        os << **it << std::endl;
    return (os);
}
