#include 'quanlynhahang.h'

Dish::Dish(int id = 0, string name = "", int price = 0){
    ID = id;
    NAME = name;
    PRICE = price;        
}
int Dish::getID(){return ID;}
string Dish::getName(){return NAME;}
int Dish::getPrice(){return PRICE;}

void Dish::setID(){
    int id;
    cout << "Nhap ID: ";
    cin >> id;
    ID = id;
}
void Dish::setName(){
    string name;
     cout << "Nhapp ten mon an: ";
     cin >> name;
     NAME = name;
}
void Dish::setPrice(){
    int price;
    cout << "Nhap gia: ";
    cin >> price;
    PRICE = price;
 }

void Dish::information(){      
    cout << ID << "\t" << NAME << "\t" << PRICE <<endl;
}

DishOnTable::DishOnTable(int numberDish = 0){
    NUMBERDISH = numberDish;
}

int DishOnTable::getNumberDish(int numberTable){return NUMBERDISH;}

void DishOnTable::setNumberDish(int numberTable){

}


Table::Table(int numberTable, bool status){
    NUMBERTABLE = numberTable++;
    STATUS = status;
}

int Table::getNumberTable(){return NUMBERTABLE;}
bool Table::getStatus(){return STATUS;}

void Table::setNumberTable(){

}
void Table::setStatus(){

}
list <DishOnTable>& Table::getDatabaseDishOnTable(){

}


void setTable(list<Table>& databaseTable){
    cout <<"Nhap so ban: ";
    int number;
    cin >> number;
    for (int i = 0; i < number; i++){
        Table table(i+1, false);
        databaseTable.push_back(table);
    }
    cout << "Da them " << number << " ban !\n";

}

void addDish(list<Dish>& databaseDishOnMenu){
    string name;
    int id, price;
    while (1)
    {
        cout << "Nhap ID mon an: ";
        cin >> id;

        cout << "Nhap ten mon an: ";
        cin >> name;

        cout << "Nhap gia tien mon an: ";
        cin >> price;

        Dish dish(id, name, price);
        databaseDishOnMenu.push_back(dish);
        cout << "Them mon an thanh cong\n";
        cout << "ID |\tName |\tPrice |\n";
        for (Dish dish : databaseDishOnMenu){
            dish.information();
        }
        int con;
        cout << "Tiep tuc them mon an. Chon:\n1. Tiep tuc\n2.Thoat\n";
        cin >> con;
        if (con == 2) return;
    }
}

void updateDish(list<Dish>& databaseDishOnMenu){
    int id;

        cout << "ID |\tName |\tPrice |\n";
        for (Dish dish : databaseDishOnMenu){
            dish.information();
        }
        cout << "Nhap ID mon an can sua: ";
        cin >> id;
        for (Dish &dish : databaseDishOnMenu){
            if (dish.getID() == id){
                cout << "1. Sua ten\n2. Sua gia\n3. Thoat\n";
                int option;
                cin >> option;
                switch (option)
                {
                case 1:
                    dish.setName();
                    break;
                    
                case 2:
                    dish.setPrice();
                    break;

                case 3:
                    return;

                default:
                    break;
                }
                if (option > 3 || option < 1) cout << "Nhap khong hop le! Nhap lai: ";
                else cout << "Da sua xong\n";

            }
        }
        cout << "ID |\tName |\tPrice |\n";
        for (Dish dish : databaseDishOnMenu){
            dish.information();
        }
        
    
   
}

void deleteDish(list<Dish>& databaseDishOnMenu){
    int id;
    cout << "ID |\tName |\tPrice |\n";
        for (Dish dish : databaseDishOnMenu){
            dish.information();
        }
    flag_sure: cout << "Nhap ID mon an can xoa: ";
    cin >> id;
    int sure;
    cout << "Ban co chac chan khong?\n1. Co\n2. Khong\n";
    cin >> sure;
    if (sure == 1){
        list<Dish>::iterator po;
        for (po = databaseDishOnMenu.begin(); po != databaseDishOnMenu.end(); po++){
            if(po->getID() == id){
            databaseDishOnMenu.erase(po);
            cout <<"Da xoa mon " <<po->getName()<<" thanh cong\n";
            cout << "ID |\tName |\tPrice |\n";
            for (Dish dish : databaseDishOnMenu){
                dish.information();
            }
         }
        // else if (dish.getID() != id){
        //     cout << "ID khong ton tai\n";
        // }
        // else break;
    }
    }
    else if (sure == 2) goto flag_sure;

}

void displayInfor(list<Dish> databaseDishOnMenu){
    cout << "ID |\tName |\tPrice |\n";
    for (Dish dish : databaseDishOnMenu){
        dish.information();
    }
}



void displayTable(list<Table>& databaseTable){
    if (databaseTable.size() == 0){
        cout << "Quan Ly vui long set so ban!";
    }
    else {
        cout << "Danh sach ban: \n";
        for (Table table : databaseTable){
        
            cout << table.getNumberTable() << "\t";
        }
        cout << endl;
        for (Table table : databaseTable){
            cout << table.getStatus() << "\t";
        }
    }
}

void Manager(list<Dish>& databaseDishOnMenu, list<Table>& databaseTable){
    int key;
    while (1){
        cout << "MANAGER\n";
        cout << "1. Set so ban\n2. Them mon an\n3. Sua mon an\n4. Xoa mon an\n5. Hien thi danh sach mon an\n6. Thoat\n";
        cin >> key;
        switch (key){
            case 1:
                setTable(databaseTable);
                break;
            case 2:
                addDish(databaseDishOnMenu);
                break;
            case 3:
                updateDish(databaseDishOnMenu);
                break;
            case 4:
                deleteDish(databaseDishOnMenu);
                break;
            case 5:
                displayInfor(databaseDishOnMenu);
                break;
            case 6:
                return;
                break;

        }
    }
}

void Staff(list<Dish>& databaseDishOnMenu, list<Table>& databaseTable){
    cout << "STAFF\n";
    displayTable(databaseTable);
    int nOtable;
    cout << "Nhap so ban: ";
    cin >> nOtable;
    for (Table& table : databaseTable){
        if (nOtable == table.getNumberTable()) {
            cout << "ID |\tName |\tPrice |\n";
            for (Dish dish : databaseDishOnMenu){
                dish.information();
            }
            cout << "BAN " << nOtable << endl;
            cout << "1. Them mon\n2. Xoa mon\n3. danh sach mon\n4. thanh toan\n0. Quay lai";
            int choice; cin >> choice;
            cout << "Moi nhap chuc nang: ";
            switch (choice)
            {
            case 1:
                /* code */
                break;
            
            default:
                break;
            }

        }
    }
}

void addDishOnTable(list<Dish>& databaseDishOnMenu, list<Table>& databaseTable, list <DishOnTable>& databaseDishOnTable){
    displayInfor(databaseDishOnMenu);
    cout << "Moi ban nhap ID mon: " << endl;
    int id; cin >> id;
    for (Dish& dish : databaseDishOnMenu){
        if (dish.getID() == id){
            cout << "Ban da chon mon: " << dish.getName() << endl;
            int SL; 
            cout << "Nhap so luong: ";
            cin >> SL;
            DishOnTable monmoi(SL);
            databaseDishOnTable.push_back(monmoi);
            cout << "Them mon thanh cong\n";

        }
    }
}
















