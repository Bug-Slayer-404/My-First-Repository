#include "Manager.h"

#include <iostream>
#include <limits>

bool cinCheck() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "输入无效！\n";
        return false;
    }
    return true;
}

std::vector<Account>& AccountManager::getAccounts() { return accounts; }

void AccountManager::clearAccount() {
    std::cout << "是否真的清除？清除后无法恢复！(Y/N)\n";
    char op;
    std::cin >> op;
    if (op == 'Y' || op == 'y') {
        accounts.clear();
        std::cout << "\n=====数据已清除!=====\n";
    } else
        std::cout << "\n=====取消删除数据=====\n";
}

void AccountManager::addAccount() {
    Account account;

    std::cout << "请输入平台：";
    std::cin >> account.platform;

    std::cout << "请输入用户名：";
    std::cin >> account.username;

    std::cout << "请输入密码：";
    std::cin >> account.key;

    std::cin.ignore();
    std::cout << "请输入备注：";
    std::getline(std::cin, account.note);

    accounts.push_back(account);

    std::cout << "添加成功！\n";
}

void AccountManager::showAccounts() {
    if (accounts.empty()) {
        std::cout << "当前没有账号\n";
        return;
    }

    std::cout << "\n===== 账号信息 =====\n";

    for (const auto& account : accounts) {
        std::cout << "平台：" << account.platform << '\n';
        std::cout << "用户名：" << account.username << '\n';
        std::cout << "密码名：" << account.key << '\n';
        std::cout << "备注：" << account.note << '\n';
        std::cout << "--------------------\n";
    }

    std::cout << "====================\n";
}

void AccountManager::deleteAccount() {
    std::vector<MatchAccount> idx;
    std::string platform;
    int choose, pos = 0;
    bool flag = true;

    std::cout << "请输入账户所在的平台：";
    std::cin >> platform;

    for (const auto& account : accounts) {
        if (account.platform == platform) {
            idx.push_back({pos, account.username, account.key, account.note});
        }

        ++pos;
    }

    pos = 0;
    if (idx.size() == 0) {
        std::cout << "该平台没有账户！\n";
    } else {
        std::cout << "\n找到" << idx.size() << "个账户\n";
        for (const auto& cur : idx) {
            std::cout << "[" << pos++ << "]\n"
                      << "用户名：" << cur.username << '\n'
                      << "密码名：" << cur.key << '\n'
                      << "备注:" << cur.note;
            std::cout << "\n--------------------\n";
        }
        do {
            std::cout << "请输入删除序号：";
            std::cout.flush();
            std::cin >> choose;

            if (!cinCheck()) {
                continue;
            }

            if (choose > pos - 1 || choose < 0) {
                std::cout << "不合法！\n";
            } else {
                accounts.erase(accounts.begin() + idx[choose].idx);
                std::cout << "已删除！\n";
                flag = false;
            }
        } while (flag);
    }
};

void AccountManager::updateAccount() {
    std::vector<MatchAccount> idx;
    std::string platform;
    int choose, pos = 0;
    std::string curname, curnote, curkey;
    bool flag = true;

    std::cout << "请输入账户所在的平台：";
    std::cin >> platform;
    for (const auto& account : accounts) {
        if (account.platform == platform) {
            idx.push_back({pos, account.username, account.key, account.note});
        }
        ++pos;
    }
    pos = 0;
    if (idx.size() == 0) {
        std::cout << "该平台没有账户！\n";
    } else {
        std::cout << "\n找到" << idx.size() << "个账户\n";
        for (const auto& cur : idx) {
            std::cout << "[" << pos++ << "]\n"
                      << "用户名：" << cur.username << '\n'
                      << "密码：" << cur.key << '\n'
                      << "备注:" << cur.note;
            std::cout << "\n--------------------\n";
        }
        do {
            std::cout << "请输入被更改账户的序号：";
            std::cout.flush();
            std::cin >> choose;

            if (!cinCheck()) {
                continue;
            }

            if (choose > pos - 1 || choose < 0) {
                std::cout << "不合法！\n";
            } else {
                std::string op;
                std::cout
                    << "改什么？（用户名：username；备注：note；密码：key；全"
                       "部：all）\n";
                std::cin >> op;

                if (op == "username" || op == "all") {
                    std::cout << "更改后的用户名：";
                    std::cin >> curname;
                    accounts[idx[choose].idx].username = curname;
                }

                if (op == "key" || op == "all") {
                    std::cout << "更改后的密码：";
                    std::cin >> curkey;
                    accounts[idx[choose].idx].key = curkey;
                }

                if (op == "note" || op == "all") {
                    std::cout << "更改后的备注：";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                    '\n');
                    std::getline(std::cin, curnote);
                    accounts[idx[choose].idx].note = curnote;
                }

                if (op != "username" && op != "key" && op != "note" &&
                    op != "all") {
                    std::cout << "无效输入！\n";
                } else {
                    std::cout << "已更改！\n";
                    flag = false;
                }
            }
        } while (flag);
    }
}

void AccountManager::findAccount() {
    std::string platform;
    int cnt = 0;

    std::cout << "请输入平台：";
    std::cin >> platform;

    for (const auto& account : accounts) {
        if (account.platform == platform) {
            ++cnt;

            std::cout << "\n平台：" << account.platform << '\n';
            std::cout << "用户名：" << account.username << '\n';
            std::cout << "密码：" << account.key << '\n';
            std::cout << "备注：" << account.note << '\n';
        }
    }

    if (cnt == 0) {
        std::cout << "没有找到该平台的账号\n";

    } else {
        std::cout << "\n共找到 " << cnt << " 个账号\n";
    }
}

void AccountManager::help() {
    std::cout << "\n===== 帮助 =====\n";

    std::cout << "add    - 输入账号\n";
    std::cout << "show   - 输出所有账号\n";
    std::cout << "find   - 搜索账号\n";
    std::cout << "help   - 显示帮助\n";
    std::cout << "delete - 删除指定账号\n";
    std::cout << "update - 更新指定账号\n";
    std::cout << "clear  - 清除全部数据\n";
    std::cout << "save   - 保存数据（停止程序时会自动保存）\n";
    std::cout << "stop   - 停止程序\n";

    std::cout << "================\n";
}