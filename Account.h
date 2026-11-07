/*
  File        : Account.h
  Description : Declares the Account class, which stores one customer's
                bank account information (id, name, and balance).
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
class Account {
    private:
        int* accountId;             // pointer to dynamic memory holding the account id
        std::string customerName;   // customer account name (can have spaces)
        float balance;              // current account balance

    public:
        // constructors and destructor
        Account();
        Account(int id, const std::string& name, float bal);
        Account(const Account& other);
        Account& operator=(const Account& other);
        ~Account();

        // getters
        int getAccountId() const;
        std::string getCustomerName() const;
        float getBalance() const;

        // setters
        void setAccountId(int id);
        void setCustomerName(const std::string& name);
        void setBalance(float bal);

        // banking operations
        void deposit(float amount);
        bool withdraw(float amount);

        // overloaded operator
        Account& operator+=(Account& srcAcct);
};

#endif // ACCOUNT_H