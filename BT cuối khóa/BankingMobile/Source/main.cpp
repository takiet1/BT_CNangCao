#include <iostream>
#include <thread>
#include <chrono>
#include <BankingApp.h>

using namespace std;


int main() {
    BankingApp acc1("kiet", "123", 100.0);

    int choice;
    do {
        cout << "========== Mobile Banking ==========" << endl;
        cout << "1. Dang nhap" << endl;
        cout << "2. Kiem tra so du" << endl;
        cout << "3. Nap tien" << endl;
        cout << "4. Rut tien" << endl;
        cout << "5. Thoat" << endl;
        cout << "====================================" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                acc1.login(&acc1);
                break;
            case 2:
                acc1.checkBalance();
                break;
            case 3:
                acc1.deposit();
                break;
            case 4:
                acc1.withdraw();
                break;
            case 5:
                // Dung vong lap va thoat khoi chuong trinh
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai." << endl;
                break;
        }
    } while (choice != 5);

    
    thread notificationThread(&BankingApp::automaticNotification, &acc1);

    
    notificationThread.join();

    return 0;
}