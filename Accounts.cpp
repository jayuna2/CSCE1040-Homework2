/*
  File        : Accounts.cpp
  Description : Defines the Accounts class methods.
*/

#include <cstddef>
#include "Accounts.h"

// destructor: delete every dynamic Account object in the vector
Accounts::~Accounts()
{
    for (int i = 0; i < size(); ++i)
    {
        delete acc.at(i); // deleting each account object
    }
}

// add a pointer to a new dynamic Account object to the vector
void Accounts::addAcct(Account* val)
{
    acc.push_back(val); // pushing back new account pointer into the vector
}

// search the vector for an account with the given id
Account* Accounts::findAcct(const int acctId)
{
    for (int i = 0; i < size(); ++i)
    {
        if (acc.at(i)->getAccountId() == acctId)
        {
            return acc.at(i); // match found
        }
    }
    return NULL; // if no match, NULL is returned
}

// return the account pointer stored at index i
Account* Accounts::at(const int i) const
{
    return acc.at(i);
}

// return how many accounts are stored in the vector
int Accounts::size() const
{
    return (int)acc.size();
}