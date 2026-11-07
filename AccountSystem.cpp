/*
  File        : AccountSystem.cpp
  Description : Defines the AccountSystem class methods.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "AccountSystem.h"

using namespace std;

/*
  Function    : addAccount
  Description : Prompts the user for an account id, customer name, and
                initial deposit. If the id is not already used, a new
                dynamic Account is created, filled in with mutators, and
                added to the container. A status message is printed.
*/
void AccountSystem::addAccount()
{
    int acctId;        // account id entered by the user
    string name;       // customer account name (can have spaces)
    float amount;      // initial deposit amount
    Account* acct;     // pointer to the new dynamic account

    // read the account id
    cout << "Enter account id: ";
    cin >> acctId;

    // do not add the account if the id already exists
    if (accts.findAcct(acctId) != NULL)
    {
        cout << "Error: account id " << acctId << " already exists." << endl;
        return;
    }

    // read the customer name (ignore the leftover newline first)
    cout << "Enter customer account name: ";
    cin.ignore();
    getline(cin, name);

    // read the initial deposit amount
    cout << "Enter initial deposit amount: $ ";
    cin >> amount;

    // create the dynamic account and set its data using mutators
    acct = new Account();
    acct->setAccountId(acctId);
    acct->setCustomerName(name);
    acct->setBalance(amount);

    // add the account to the container
    accts.addAcct(acct);

    // print status message with 2 decimal places
    cout << fixed << setprecision(2);
    cout << "Added new account id " << acctId
         << " with initial balance $" << amount << endl;
}

/*
  Function    : deposit
  Description : Prompts the user for an account id and a deposit amount.
                If the account exists, the amount is deposited and a
                status message is printed. Otherwise an error is printed.
*/
void AccountSystem::deposit()
{
    int acctId;        // account id entered by the user
    float amount;      // amount of money to deposit
    Account* acct;     // pointer to the account found in the container

    // cannot deposit if there are no accounts in the system
    if (accts.size() == 0)
    {
        cout << "Empty account list." << endl;
        return;
    }

    // read the account id and search for the account
    cout << "Enter account id: ";
    cin >> acctId;
    acct = accts.findAcct(acctId);

    // account not found, print error and stop
    if (acct == NULL)
    {
        cout << "Error: account with id " << acctId << " not found." << endl;
        return;
    }

    // read the deposit amount
    cout << "Enter the deposit amount: $ ";
    cin >> amount;

    // deposit the amount into the account
    acct->deposit(amount);

    // print status message with 2 decimal places
    cout << fixed << setprecision(2);
    cout << "Deposited $" << amount << " into account id " << acctId << endl;
}

/*
  Function    : withdraw
  Description : Prompts the user for an account id and a withdraw amount.
                If the account exists and has enough balance, the amount
                is withdrawn and a status message is printed. Otherwise an
                error message is printed.
*/
void AccountSystem::withdraw()
{
    int acctId;        // account id entered by the user
    float amount;      // amount of money to withdraw
    Account* acct;     // pointer to the account found in the container

    // cannot withdraw if there are no accounts in the system
    if (accts.size() == 0)
    {
        cout << "Empty account list." << endl;
        return;
    }

    // read the account id and search for the account
    cout << "Enter account id: ";
    cin >> acctId;
    acct = accts.findAcct(acctId);

    // account not found, print error and stop
    if (acct == NULL)
    {
        cout << "Error: account with id " << acctId << " not found." << endl;
        return;
    }

    // read the withdraw amount
    cout << "Enter the withdraw amount: $ ";
    cin >> amount;

    cout << fixed << setprecision(2);

    // not enough balance, print error and stop
    if (amount > acct->getBalance())
    {
        cout << "Error: failed to withdraw $" << amount
             << " from account id " << acctId << endl;
        return;
    }

    // withdraw the amount from the account
    acct->withdraw(amount);

    // print status message
    cout << "Withdrawn $" << amount << " from account id " << acctId << endl;
}

/*
  Function    : transfer
  Description : Prompts the user for a source account id and a destination
                account id. If both accounts exist, the overloaded +=
                operator (destAcct += srcAcct) asks for the transfer amount
                and moves the money. If the transfer worked, a status
                message is printed. Otherwise an error message is printed.
*/
void AccountSystem::transfer()
{
    int srcId;           // source account id entered by the user
    int destId;          // destination account id entered by the user
    float oldBalance;    // source account balance before the transfer
    float amount;        // amount that was actually transferred
    Account* srcAcct;    // pointer to the source account
    Account* destAcct;   // pointer to the destination account

    // cannot transfer if there are no accounts in the system
    if (accts.size() == 0)
    {
        cout << "Empty account list." << endl;
        return;
    }

    // read source and destination account ids
    cout << "Enter source account id: ";
    cin >> srcId;
    cout << "Enter destination account id: ";
    cin >> destId;

    // search for both accounts
    srcAcct = accts.findAcct(srcId);
    destAcct = accts.findAcct(destId);

    // either account not found, print error and stop
    if (srcAcct == NULL || destAcct == NULL)
    {
        cout << "Error: Source or destination account number not found. "
             << "Operation failed." << endl;
        return;
    }

    // remember the source balance before the transfer
    oldBalance = srcAcct->getBalance();

    // overloaded += operator reads the amount and moves the money
    // (it prints its own error message if the transfer fails)
    *destAcct += *srcAcct;

    // find out how much money actually left the source account
    amount = oldBalance - srcAcct->getBalance();

    // print status message only if money was transferred
    if (amount > 0)
    {
        cout << fixed << setprecision(2);
        cout << "Successfully transferred amount $" << amount
             << " from source account id " << srcId
             << " to destination account id " << destId << endl;
    }
}

/*
  Function    : printAccounts
  Description : Prints the account id, customer name, and balance of
                every account in a table. Prints a message if there
                are no accounts.
*/
void AccountSystem::printAccounts() const
{
    Account* acct;     // pointer to the current account being printed
    string line = "+-------------------------------------------------------+";

    // nothing to print if there are no accounts
    if (accts.size() == 0)
    {
        cout << "Empty account list." << endl;
        return;
    }

    // print the table header
    cout << line << endl;
    cout << "| Acct | Customer Account Name          | Balance        |" << endl;
    cout << line << endl;

    // print one row for each account
    cout << fixed << setprecision(2);
    for (int i = 0; i < accts.size(); ++i)
    {
        acct = accts.at(i);
        cout << "| " << setw(4) << acct->getAccountId()
             << " | " << left << setw(30) << acct->getCustomerName()
             << " | $ " << right << setw(12) << acct->getBalance()
             << " |" << endl;
        cout << line << endl;
    }
}

/*
  Function    : loadAccounts
  Description : Loads accounts from the given file. Each line in the
                file has the format: account id,balance,customer name
*/
void AccountSystem::loadAccounts(string fileName)
{
    ifstream inFile;       // input file stream
    string line;           // one line read from the file
    string idStr;          // account id part of the line
    string balanceStr;     // balance part of the line
    string name;           // customer name part of the line
    Account* acct;         // pointer to the new dynamic account

    // open the file and stop if it cannot be opened
    inFile.open(fileName.c_str());
    if (!inFile.is_open())
    {
        cout << "Error: unable to open " << fileName << "." << endl;
        return;
    }

    // read the file one line at a time
    while (getline(inFile, line))
    {
        // skip empty lines
        if (line == "")
        {
            continue;
        }

        // split the line by commas
        istringstream iss(line);
        getline(iss, idStr, ',');
        getline(iss, balanceStr, ',');
        getline(iss, name);

        // create the account and add it to the container
        acct = new Account(stoi(idStr), name, stof(balanceStr));
        accts.addAcct(acct);
    }

    cout << "Customer accounts loaded successfully." << endl;
    inFile.close();
}

/*
  Function    : saveAccounts
  Description : Saves all accounts to the given file. Each line in the
                file has the format: account id,balance,customer name
*/
void AccountSystem::saveAccounts(string fileName) const
{
    ofstream outFile;      // output file stream
    Account* acct;         // pointer to the current account being saved

    // open the file and stop if it cannot be opened
    outFile.open(fileName.c_str());
    if (!outFile.is_open())
    {
        cout << "Error: unable to open " << fileName << " for writing." << endl;
        return;
    }

    // write each account on its own line
    outFile << fixed << setprecision(2);
    for (int i = 0; i < accts.size(); ++i)
    {
        acct = accts.at(i);
        outFile << acct->getAccountId() << "," << acct->getBalance()
                << "," << acct->getCustomerName() << endl;
    }

    outFile.close();
}