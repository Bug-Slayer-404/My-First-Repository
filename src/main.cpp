#include <iostream>

#include "File.h"
#include "Manager.h"

int main() {
    std::ios::sync_with_stdio(0);
    AccountManager manager;
    loadAccounts(manager.getAccounts());

    std::string op;
    std::cout << "欢迎使用 ZekeGuo 的账户管理器，使用 help 指令获取使用方法\n";

    while (true) {
        std::cin >> op;

        if (op == "add")
            manager.addAccount();
        else if (op == "show")
            manager.showAccounts();
        else if (op == "find")
            manager.findAccount();
        else if (op == "help")
            manager.help();
        else if (op == "update")
            manager.updateAccount();
        else if (op == "save") {
            saveAccounts(manager.getAccounts());
            std::cout << "\n=====已保存=====\n";
        } else if (op == "delete")
            manager.deleteAccount();
        else if (op == "clear")
            manager.clearAccount();
        else if (op == "stop") {
            saveAccounts(manager.getAccounts());
            break;
        } else {
            std::cout << "无效指令\n";
        }
    }

    return 0;
}