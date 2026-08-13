#ifndef FILE_H
#define FILE_H

#include <vector>

#include "Account.h"

void loadAccounts(std::vector<Account>& accounts);

void saveAccounts(const std::vector<Account>& accounts);

#endif