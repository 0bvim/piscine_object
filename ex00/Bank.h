//
// Created by Vinicius de Freitas Pereira on 20/09/26.
//

#ifndef PISCINE_OBJECT_BANK_H
#define PISCINE_OBJECT_BANK_H
#include "Account.h"


class Bank {
private:
    int _liquidity;
    std::vector<Account *> _clientAccounts;

public:
    Bank();
    Bank(const int liquidity);
    Bank(Bank const &rhs);
    Bank &operator=(Bank const &rhs);
    ~Bank();

    int getLiquidity() const;
    std::vector<Account *> getClientAccounts() const;

    void setLiquidity(int liquidity);
    void addClientAccount(Account *account);

    friend std::ostream& operator<<(std::ostream& os, const Bank& bank);
};

#endif //PISCINE_OBJECT_BANK_H
