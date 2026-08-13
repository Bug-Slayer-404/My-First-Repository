#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

struct MatchAccount {
    int idx;
    std::string username;
    std::string key;
    std::string note;
};

struct Account {
    std::string platform;
    std::string username;
    std::string key;
    std::string note;
};

#endif