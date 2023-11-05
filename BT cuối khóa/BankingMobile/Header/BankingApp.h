#ifndef _BANKING_APP_H
#define _BANKING_APP_H


#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class BankingApp {
private:
    string USERNAME;
    string PASSWORD;
    double BALANCE;

public:
    BankingApp(string username, string password, double balance){
        USERNAME = username;
        PASSWORD = password;
        BALANCE = balance;
    }

    bool logincheck (string tk, string mk);
    void login(BankingApp *acc);
    void checkBalance();
    void deposit();
    void withdraw();
    void automaticNotification();
    
};

#endif