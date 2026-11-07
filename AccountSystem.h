/*
  File        : AccountSystem.h
  Description : Declares the AccountSystem class, which provides the
                bank account system operations.
*/

#ifndef ACCOUNTSYSTEM_H
#define ACCOUNTSYSTEM_H

#include "Accounts.h"

class AccountSystem
{
    public:
        // Part 3 (Krishna): deposit, withdraw, and transfer
        void deposit();     // deposit money into an existing account
        void withdraw();    // withdraw money from an existing account
        void transfer();    // transfer money from source to destination account
        void printAccounts() const; //print acc data
        void loadAccounts();
        void saveAccounts() const;

    private:
        Accounts accts;     // container that holds all the accounts
};

#endif
