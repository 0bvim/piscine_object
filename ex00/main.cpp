//
// Created by Vinicius de Freitas Pereira on 20/09/26.
//
#include "Bank.hpp"
#include "Account.hpp"
#include <iostream>

int main()
{
    Bank bank = Bank(100);
    Account acc = Account(123, 150);

    bank.addClientAccount(&acc);
    std::cout << bank.getLiquidity() << std::endl;
    std::cout << acc.getValue() << std::endl;
}