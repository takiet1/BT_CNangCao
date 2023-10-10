#include <iostream>
#include <string>
#include <list>
#include "quanlynhahang.h"



using namespace std;


int main(int argc, char const *argv[]){

    list <Dish> databaseDishOnMenu;
    list <Table> databaseTable;
    list <DishOnTable> databaseDishOnTable;

    Dish dish1(101, "ga", 10);
    Dish dish2(102, "ca", 20);
    Dish dish3(103, "thit", 30);

    databaseDishOnMenu.push_back(dish1); 
    databaseDishOnMenu.push_back(dish2); 
    databaseDishOnMenu.push_back(dish3); 
    
    

    while (1)
    {
        cout << "Ban la: \n1. Manager\n2. Staff\n";
        int key;
        cin >> key;

        if(key == 1) {Manager(databaseDishOnMenu, databaseTable); break;}
        else if(key == 2) {Staff(databaseDishOnMenu, databaseTable); break;}
        else cout <<"Nhap sai cu phap!\nMoi Nhap lai: ";
    }
    Staff(databaseDishOnMenu, databaseTable);
    
    return 0;
}
