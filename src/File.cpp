#include "File.h"

#include <fstream>
#include <sstream>

void loadAccounts(std::vector<Account>& accounts) {
    std::ifstream fin("./data/accounts.txt");

    if (!fin) return;

    std::string line;

    while (std::getline(fin, line)) {
        std::stringstream ss(line);

        Account account;

        std::getline(ss, account.platform, '|');
        std::getline(ss, account.username, '|');
        std::getline(ss, account.note);

        accounts.push_back(account);
    }
}

void saveAccounts(const std::vector<Account>& accounts) {
    std::ofstream fout("./data/accounts.txt");

    for (const auto& account : accounts) {
        fout << account.platform << '|' << account.username << '|'
             << account.note << '\n';
    }
}