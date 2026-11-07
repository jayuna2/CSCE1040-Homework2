/*
  File        : Accounts.h
  Description : Declares the Accounts class, a container class that
                holds pointers to dynamic objects of the Account class.
*/

#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <vector>
#include "Account.h"

class Accounts
{
    private:
        std::vector<Account *> acc;   // pointers to dynamic Account objects

    public:
        ~Accounts();                              // delete all dynamic accounts
        void addAcct(Account* val);               // add an account to the vector
        Account* findAcct(const int acctId);      // find account by id, NULL if not found
        Account* at(const int i) const;           // return account at index i
        int size() const;                         // return number of accounts
};

#endif