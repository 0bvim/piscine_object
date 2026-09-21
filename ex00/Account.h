//
// Created by Vinicius de Freitas Pereira on 20/09/26.
//

#ifndef PISCINE_OBJECT_ACCOUNT_H
#define PISCINE_OBJECT_ACCOUNT_H



class Account {
private:
    int _id;
    int _value;

public:
    Account();
    Account(const int id, const int value);
    Account(Account const &rhs);
    Account &operator=(Account const &rhs);
    ~Account();

    int getId() const;
    int getValue() const;

    void setId(int id);
    void setValue(int value);

    friend std::ostream& operator<<(std::ostream& os, const Account& account);
};



#endif //PISCINE_OBJECT_ACCOUNT_H
