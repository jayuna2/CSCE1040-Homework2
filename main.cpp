/*
  Author(s)   : Jayuna Khatiwada, Krishna Khanal, Tayler Wallace, <Member 4>
  Course      : CSCE 1040.400 Fall 2026
  Instructor  : Dr. Amar Maharjan
  Date        : 11/06/2026
  Description : This program implements a bank account system. The program
                displays a menu of several operations and prompts users to
                enter a selection to
                    1. Add a new account
                    2. Deposit into the account
                    3. Withdraw from the account
                    4. Transfer into the account
                    5. Print a list of all accounts
                    6. End transaction (Exit)
  Tasks       :
                <Part 1 member>:
                    1) Account class (Account.h, Account.cpp)
                <Part 2 member>:
                    1) Accounts container class (Accounts.h, Accounts.cpp)
                    2) Add new account and print all accounts
                Krishna Khanal:
                    1) Deposit, withdraw, and transfer operations
                Tayler Wallace:
                    1) Load accounts from file and save accounts to file
                    2) main.cpp menu logic and makefile
*/

#include <iostream>
#include <limits>
#include "AccountSystem.h"

using namespace std;

int main()
{
    AccountSystem bank;     // object that runs all the bank operations
    int choice = 0;         // menu option entered by the user

    // display department, course, and student information
    cout << "+----------------------------------------------+" << endl;
    cout << "|       Computer Science and Engineering       |" << endl;
    cout << "|        CSCE 1040 - Computer Science II       |" << endl;
    cout << "|   Jayuna Khatiwada  EUID  euid@my.unt.edu    |" << endl;
    cout << "|   Krishna Khanal    kk1374  krishnakhanal2@my.unt.edu    |" << endl;
    cout << "|   Tayler Wallace    EUID  euid@my.unt.edu    |" << endl;
    cout << "|   Member 4          EUID  euid@my.unt.edu    |" << endl;
    cout << "+----------------------------------------------+" << endl;

    // load customer accounts from the file when the system starts
    bank.loadAccounts("accounts.dat");

    // keep showing the menu until the user chooses to exit
    do
    {
        // display the menu
        cout << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "| Enter account selection             |" << endl;
        cout << "| 1 : Add new account                 |" << endl;
        cout << "| 2 : Deposit into account            |" << endl;
        cout << "| 3 : Withdraw from account           |" << endl;
        cout << "| 4 : Transfer into account           |" << endl;
        cout << "| 5 : Print a list of all accounts    |" << endl;
        cout << "| 6 : End transaction (Exit)          |" << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "> ";

        // read the menu choice; if it is not a number, clear the input
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;
        }

        // process the user's choice
        switch (choice)
        {
            case 1:
                bank.addAccount();
                break;
            case 2:
                bank.deposit();
                break;
            case 3:
                bank.withdraw();
                break;
            case 4:
                bank.transfer();
                break;
            case 5:
                bank.printAccounts();
                break;
            case 6:
                // save customer accounts to the file before exiting
                bank.saveAccounts("accounts.dat");
                cout << "Thank you for running the program. Goodbye!" << endl;
                break;
            default:
                cout << "Error: Invalid selection. Enter a value between 1-6." << endl;
        }
    } while (choice != 6);

    return 0;
}