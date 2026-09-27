//
// Created by Vinicius de Freitas Pereira on 20/09/26.
//

#include "Bank.hpp"

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
    _clientAccounts.push_back(account);
}

void Bank::removeClientAccount(Account* account)
{
}

void Bank::changeClientId(Account* account, int newId)
{
}

void Bank::changeAccountValue(Account* account, int newValue)
{
}

void Bank::checkFunds(Account* account)
{
}

void Bank::withdrawFunds(Account* account, int amount)
{
}

void Bank::depositFunds(Account* account, int amount)
{
}

bool Bank::canLoanMoney(Account* account, int amount)
{
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
