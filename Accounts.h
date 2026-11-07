#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include "Account.h"
#include<vector>

class Accounts {
    private:
    vector<Account *> acc; // pointer for holding object of account class

    public:
    ~Accounts(){
        for(int i = 0; i < acc.size(); ++i)
        {
            delete acc[i];
        }
    }

    void Accounts::addAcct(Account* val){
        acc.push_back(val);
    }

    
};

#endif 