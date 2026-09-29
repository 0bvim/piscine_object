//
// Created by Vinicius de Freitas Pereira on 20/09/26.
//
#include "Bank.hpp"
#include "Account.hpp"
#include <iostream>

int main()
{
    Bank bank = Bank(100);
    Account acc1 = Account(123, 150);
    Account acc2 = Account(123, 100);

    bank.addClientAccount(&acc1);
    bank.addClientAccount(&acc2);
    std::cout << bank.getLiquidity() << std::endl;
    std::cout << bank.getClientAccounts().size() << std::endl;
    std::cout << "bank liquidity: " << bank.getLiquidity() << std::endl;
    std::cout << acc1.getValue() << std::endl;
    std::cout << acc2.getValue() << std::endl;
}