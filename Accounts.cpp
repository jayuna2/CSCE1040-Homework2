#include"Accounts.h"

~Accounts(){
    for(int i = 0; i < acc.size(); ++i)
        {
            delete acc[i]; // deleting each account vector.
        }
}


void Accounts::addAcct(Account* val){
        acc.push_back(val); // pushing back new object of acc to existing acc cbject vector (pointers)
}


Account* Accounts::findAcct(const int acctId){
       for (int i = 0; i < acc.size(); ++i) {
        if (acc.at(i)->getAccountId() == acctId){
            return acc.at(i);
        }
       }
      return nullptr; // if no match null pointer is returned;
}


Account* Accounts::at(const int i) const {
    return acc.at(i);
}
