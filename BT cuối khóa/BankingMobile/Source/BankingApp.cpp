#include <BankingApp.h>



bool BankingApp::logincheck (string tk, string mk){
    return (USERNAME == tk && PASSWORD == mk);
}
 
 
void BankingApp::login(BankingApp *acc) {
    bool logincheck = 0;
    string uname, pass;
    while(!logincheck){
    cout << "Enter Username: ";
    cin >> uname;
    cout << "Enter Password: ";
    cin >> pass;
    logincheck = acc->logincheck(uname, pass);
    if (!logincheck)  cout << "Nhap sai ten tai khaon hoac mat khau. Vui long thu lai!" << endl;

    else {
        cout << "Dang nhap thanh cong!" << endl;
        logincheck = 1;
        break;
        }
    }
}

void BankingApp::checkBalance() {
    cout << "So du hien tai: " << BALANCE << endl;
}

void BankingApp::deposit() {
    double amount;
    cout << "Nhap so tien can nap: ";
    cin >> amount;
    BALANCE = BALANCE + amount;
    cout << "Da nap " << amount <<" thanh cong!" << endl;
    cout << "So du: " << BALANCE;
}

void BankingApp::withdraw() {
    while (1){
    double amount;
    cout << "Nhap so tien can rut: ";
    cin >> amount;
    if (amount > BALANCE) cout << "So du khong du moi nhap lai" << endl;
    else {
        BALANCE = BALANCE - amount;
        cout << "Da rut " << amount <<" thanh cong!" << endl;
        cout << "So du: " << BALANCE;
        break;
        }
    }    
}

void BankingApp::automaticNotification() {
    while (true) {
    cout << "Thong bao tu dong tu ngan hang. Giao dich ket thuc!" << endl;       
    this_thread::sleep_for(chrono::seconds(10)); 
    }
}