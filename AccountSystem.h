/*
  File        : AccountSystem.h
  Description : Declares the AccountSystem class, which provides the
                bank account system operations.
*/

#ifndef ACCOUNTSYSTEM_H
#define ACCOUNTSYSTEM_H

#include <string>
#include "Accounts.h"

class AccountSystem
{
    public:
        // Part 2: add an account and print all accounts
        void addAccount();                  // add a new account to the system
        void printAccounts() const;         // print all accounts in a table

        // Part 3 (Krishna): deposit, withdraw, and transfer
        void deposit();     // deposit money into an existing account
        void withdraw();    // withdraw money from an existing account
        void transfer();    // transfer money from source to destination account

        // Part 4: load and save accounts using a file
        void loadAccounts(std::string fileName);        // read accounts from file
        void saveAccounts(std::string fileName) const;  // write accounts to file

    private:
        Accounts accts;     // container that holds all the accounts
};

#endif