#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
class Account {
    private:
        int* accountId;
        std::string customerName;
        float balance;

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