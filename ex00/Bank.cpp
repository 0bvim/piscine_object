//
// Created by Vinicius de Freitas Pereira on 20/09/26.
//

#include "Bank.h"

Bank::Bank()
{
    setLiquidity(0);
}

Bank::Bank(const int liquidity)
{
    setLiquidity(liquidity);
}

Bank::Bank(Bank const &rhs)
{
    *this = rhs;
}

Bank::Bank &operator=(Bank const &rhs)
{
    if (this != &rhs)
    {
        setLiquidity(rhs.getLiquidity());
        _clientAccounts = rhs.getClientAccounts();
    }
    return *this;
}

Bank::~Bank() {}

int Bank::getLiquidity() const
{
    return _liquidity;
}

std::vector<Account *> Bank::getClientAccounts() const
{
    return _clientAccounts;
}

void Bank::setLiquidity(int liquidity)
{
    _liquidity = liquidity;
}

void Bank::addClientAccount(Account *account)
{
    _clientAccounts.push_back(account);
}

friend std::ostream& operator<<(std::ostream& os, const Bank& bank)
{
    os << "Bank informations : " << std::endl;
    os << "Liquidity : " << bank.getLiquidity() << std::endl;
    for (Account &clientAccount : bank.getClientAccounts())
        os << *clientAccount << std::endl;
    return (os);
}
