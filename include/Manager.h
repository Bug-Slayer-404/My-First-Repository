#ifndef MANAGER_H
#define MANAGER_H

#include <vector>

#include "Account.h"

class AccountManager {
   private:
    std::vector<Account> accounts;

   public:
    void addAccount();
    void showAccounts();
    void findAccount();
    void updateAccount();
    void deleteAccount();
    void clearAccount();
    void help();

    std::vector<Account>& getAccounts();
};

#endif