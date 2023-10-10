#include <iostream>
#include <string>
#include <list>

using namespace std;

class Dish {
    private:
        int ID;
        string NAME;
        int PRICE;
    public:
        Dish(int id = 0, string name = "", int price = 0);

        int getID();
        string getName();
        int getPrice();

        void setID();
        void setName();
        void setPrice();

        void information();
        
};

class DishOnTable: public Dish {
    private:
        int NUMBERDISH;
    public:
        DishOnTable(int numberDish = 0);

        int getNumberDish(int numberTable);

        void setNumberDish(int numberTable);
        
};

class Table {
    private:
        int NUMBERTABLE;
        bool STATUS;
        list <DishOnTable> databaseDishOnTable;
    public:
        Table(int numberTable, bool status);

        int getNumberTable();
        bool getStatus();

        void setNumberTable();
        void setStatus();
        list <DishOnTable>& getDatabaseDishOnTable();
};

void Manager(list<Dish>& databaseDishOnMenu, list<Table>& databaseTable);

void setTable(list<Table>& databaseTable);
void addDish(list<Dish>& databaseDishOnMenu);
void updateDish(list<Dish>& databaseDishOnMenu);
void deleteDish(list<Dish>& databaseDishOnMenu);
void displayInfor(list<Dish> databaseDishOnMenu);
void displayTable(list<Table>& databaseTable);


void Staff(list<Dish>& databaseDishOnMenu, list<Table>& databaseTable);

void addDishOnTable(list<Dish>& databaseDishOnMenu, list<Table>& databaseTable, list <DishOnTable>& databaseDishOnTable);