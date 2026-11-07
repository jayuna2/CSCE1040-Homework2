/*
  File        : main.cpp
  Description : A menu-driven program for managing bank accounts.
  Author      : Tayler Wallace, 
  Course      : CSCE 1040
  Date        : Fall 2026
*/

#include <iostream>
#include <limits>
#include "Account.h"
#include "Accounts.h"
#include "AccountSystem.h"

using namespace std;

// Function prototypes
void displayMenu();
void handleDeposit(AccountSystem& system);
void handleWithdraw(AccountSystem& system);
void handleTransfer(AccountSystem& system);
void handlePrintAccounts(const AccountSystem& system);

int main() {
    AccountSystem system;
    int choice;

    // Load accounts from file (if it exists)
    system.loadAccounts();

    do {
        displayMenu();
        cout << "Enter your choice: ";

        // Input validation for menu choice
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        // Process user choice
        switch (choice) {
            case 1:
                handleDeposit(system);
                break;
            case 2:
                handleWithdraw(system);
                break;
            case 3:
                handleTransfer(system);
                break;
            case 4:
                handlePrintAccounts(system);
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

/*
  Function    : displayMenu
  Description : Displays the menu options to the user.
*/
void displayMenu() {
    cout << "\n===== Bank Account Management System =====" << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Transfer" << endl;
    cout << "4. Print All Accounts" << endl;
    cout << "5. Exit" << endl;
    cout << "==========================================" << endl;
}

/*
  Function    : handleDeposit
  Description : Handles the deposit operation.
*/
void handleDeposit(AccountSystem& system) {
    system.deposit();
}

/*
  Function    : handleWithdraw
  Description : Handles the withdraw operation.
*/
void handleWithdraw(AccountSystem& system) {
    system.withdraw();
}

/*
  Function    : handleTransfer
  Description : Handles the transfer operation.
*/
void handleTransfer(AccountSystem& system) {
    system.transfer();
}

/*
  Function    : handlePrintAccounts
  Description : Prints all accounts in the system.
*/
void handlePrintAccounts(const AccountSystem& system) {
    system.printAccounts();
}
