/*
  File        : Account.cpp
  Description : Defines the Account class methods.
*/
#include "Account.h"
#include <iostream>

// default constructor
Account::Account() {
    accountId = new int(0);
    customerName = "";
    balance = 0.0f;
}

// constructor w/ parameters
Account::Account(int id, const std::string& name, float bal) {
    accountId = new int(id);
    customerName = name;
    balance = bal;
}

// copy constructor
Account::Account(const Account& other) {
    if (other.accountId != nullptr) {
        accountId = new int(*other.accountId);
    } else {
        accountId = new int(0);
    }
    customerName = other.customerName;
    balance = other.balance;
}

// Copy assignment operator (Deep copy + self-assignment check)
Account& Account::operator=(const Account& other) {
    if (this != &other) {
        // Free existing heap allocation
        delete accountId;

        // Allocate and copy new value
        if (other.accountId != nullptr) {
            accountId = new int(*other.accountId);
        } else {
            accountId = new int(0);
        }
        customerName = other.customerName;
        balance = other.balance;
    }
    return *this;
}

// destructor
Account::~Account() {
    delete accountId;
    accountId = nullptr;
}

// getters
int Account::getAccountId() const {
    if (accountId != nullptr) {
        return *accountId;
    }
    return 0;
}

std::string Account::getCustomerName() const {
    return customerName;
}

float Account::getBalance() const {
    return balance;
}

// setters
void Account::setAccountId(int id) {
    if (accountId == nullptr) {
        accountId = new int(id);
    } else {
        *accountId = id;
    }
}

void Account::setCustomerName(const std::string& name) {
    customerName = name;
}

void Account::setBalance(float bal) {
    balance = bal;
}

// deposit
void Account::deposit(float amount) {
    if (amount > 0.0f) {
        balance += amount;
    }
}

// withdraw
bool Account::withdraw(float amount) {
    if (amount > 0.0f && balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

// overloaded += operator for transfer (destAcct += srcAcct)
Account& Account::operator+=(Account& srcAcct) {
    float transferAmount = 0.0f;
    std::cout << "Enter the transfer amount: $ ";
    if (std::cin >> transferAmount) {
        if (transferAmount <= 0.0f) {
            std::cout << "Transfer failed: Amount must be greater than zero." << std::endl;
        } else if (srcAcct.withdraw(transferAmount)) {
            this->deposit(transferAmount);
        } else {
            std::cout << "Transfer failed: Insufficient funds in source account." << std::endl;
        }
    }
    return *this;
}