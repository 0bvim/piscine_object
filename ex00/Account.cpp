//
// Created by Vinicius de Freitas Pereira on 20/09/26.
//

#include "Account.hpp"

Account::Account() : _id(-1), _value(0)
{
}

Account::Account(const int id, const int value) : _id(id), _value(value)
{
}

Account::Account(Account const& rhs)
{
    *this = rhs;
}

Account& Account::operator=(Account const& rhs)
{
    if (this != &rhs)
    {
        _id = rhs._id;
        _value = rhs._value;
    }
    return *this;
}

Account::~Account(void)
{
}

int Account::getId() const
{
    return _id;
}

int Account::getValue() const
{
    return _value;
}

void Account::setId(const int id)
{
    this->_id = id;
}

void Account::setValue(const int value)
{
    this->_value = value;
}

std::ostream& operator<<(std::ostream& p_os, const Account& p_account)
{
    p_os << "[" << p_account._id << "] - [" << p_account._value << "]";
    return (p_os);
}
