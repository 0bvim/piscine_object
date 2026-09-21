//
// Created by Vinicius de Freitas Pereira on 20/09/26.
//

#include "Account.h"

Account::Account() : _id(-1), _value(0) {}

Account::~Account() {}

Account::Account(const int id, const int value) : _id(id), _value(value) {}

Account::Account(Account const &rhs) : Account(rhs)
{
    *this = rhs;
}

Account &Account::operator=(Account const &rhs)
{
    if (this != &rhs)
    {
        _id = rhs._id;
        _value = rhs._value;
    }
    return *this;
}

friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
    p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
    return (p_os);
}
