#include <Function.h>

void addCar(vector<Vehicle*> &database){

    while (1){

        string brand;
        cout << "Brand: ";
        cin >> brand;
        

        string color;
        cout << "Color: ";
        cin >> color;
        

        int numberofwheel;
        cout << "Number Of Wheels: ";
        cin >> numberofwheel;
        

        int numberofseat;
        cout << "Number Of Seats: ";
        cin >> numberofseat;
        

        string enginetype;
        cout << "Engine Type: ";
        cin >> enginetype;
        

        Automotive* car = new Automotive(brand, color, numberofwheel, numberofseat, enginetype);
        database.push_back(car);
        int choice;
        cout << "Continue?\n1.Yes\n2.No\n";
        cin >> choice;
        if (choice == 2) return;

    }
    
}

void addMotor(vector<Vehicle*> &database){

     while (1){

        string brand;
        cout << "Brand: ";
        cin >> brand;
        

        string color;
        cout << "Color: ";
        cin >> color;
        

        int numberofwheel;
        cout << "Number Of Wheels: ";
        cin >> numberofwheel;
        

        Motor* motorbike = new Motor(brand, color, numberofwheel);
        database.push_back(motorbike);
        int choice;
        cout << "Continue?\n1.Yes\n2.No\n";
        cin >> choice;
        if (choice == 2) return;

     }
}

void displayAu(vector<Vehicle*> database){
    for (auto item : database){
        if (item->getType() == "Automotive")
        item->infor();
    }
}

void displayMo(vector<Vehicle*> database){
    for (auto item : database){
        if (item->getType() == "Motor")
        item->infor();
    }
}
void displayAll(vector<Vehicle*> database){
   for (auto item : database){
        if (item->getType() == "Automotive")
        item->infor();
    }
    for (auto item : database){
        if (item->getType() == "Motor")
        item->infor();
    }
}