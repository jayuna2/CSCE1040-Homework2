/*
  File        : AccountSystem.cpp
  Description : Defines the AccountSystem class methods.
*/

#include <iostream>
#include <iomanip>
#include "AccountSystem.h"

using namespace std;

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
  Function: PrintAccounts
  Description: Prints the id name and balance 
*/
void AccountSystem::printAccounts() const {
    cout << "\n===== All Accounts =====" << endl;
    for (int i = 0; i < accts.size(); ++i) {
        Account* acct = accts.at(i);
        cout << "ID: " << acct->getAccountId()
             << ", Name: " << acct->getCustomerName()
             << ", Balance: $" << acct->getBalance() << endl;
    }
    cout << "========================" << endl;
}

/*
  Function    : loadAccounts
  Description : Loads accounts from a file named "accounts.dat".
                Each line in the file should be in the format:
                account_id,balance,customer_name
*/
void AccountSystem::loadAccounts()
{
    ifstream inFile("accounts.dat");
    if (!inFile.is_open())
    {
        cerr << "Error: Could not open file 'accounts.dat' for reading." << endl;
        return;
    }

    string line;
    while (getline(inFile, line))
    {
        istringstream iss(line);
        string accountIdStr, balanceStr, customerName;
        getline(iss, accountIdStr, ',');
        getline(iss, balanceStr, ',');
        getline(iss, customerName, ',');

        int accountId = stoi(accountIdStr);
        float balance = stof(balanceStr);

        accts.addAccount(accountId, balance, customerName);
    }

    cout << "Accounts loaded successfully from 'accounts.dat'." << endl;
    inFile.close();
}

/*
  Function    : saveAccounts
  Description : Saves all accounts to a file named "accounts.dat".
                Each line in the file will be in the format:
                account_id,balance,customer_name
*/
void AccountSystem::saveAccounts()
{
    ofstream outFile("accounts.dat");
    if (!outFile.is_open())
    {
        cerr << "Error: Could not open file 'accounts.dat' for writing." << endl;
        return;
    }

    for (int i = 0; i < accts.size(); i++)
    {
        Account* acct = accts.getAccount(i);
        outFile << acct->getId() << "," << acct->getBalance() << "," << acct->getCustomerName() << endl;
    }

    cout << "Accounts saved successfully to 'accounts.dat'." << endl;
    outFile.close();
}
