//
// Created by Vinicius de Freitas Pereira on 20/09/26.
//

#ifndef PISCINE_OBJECT_BANK_H
#define PISCINE_OBJECT_BANK_H
#include "Account.hpp"
#include <vector>
#include <ostream>


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
    void removeClientAccount(Account *account);
    void changeClientId(Account *account, int newId);
    void changeAccountValue(Account *account, int newValue);
    void checkFunds(Account *account);
    void withdrawFunds(Account *account, int amount);
    void depositFunds(Account *account, int amount);
    bool canLoanMoney(Account *account, int amount);

    friend std::ostream& operator<<(std::ostream& os, const Bank& bank);
};

#endif //PISCINE_OBJECT_BANK_H
