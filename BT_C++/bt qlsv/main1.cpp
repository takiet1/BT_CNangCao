#include <iostream>
#include <vector>



using namespace std;


class Vehicle 
{
protected:
    string BRAND;
    string COLOR;
    int NUMBEROFWHEEL;
public:
    Vehicle(string brand, string color, int numberofwheel){
        BRAND = brand;
        COLOR = color;
        NUMBEROFWHEEL = numberofwheel; 
    }
    // string getBrand();
    // string getColor();
    // int getNumberofwheel();

    // void setBrand();
    // void setColor();
    // void setNumberofwheel();

    virtual void infor() const;
    virtual string getType() const = 0;
};

class Automotive : public Vehicle
{
private:
    int NUMBEROFSEAT;
    string ENGINETYPE;
public:
    
    Automotive(string brand, string color, int numberofwheel, int numberofseat, string enginetype) : Vehicle(brand, color, numberofwheel){
        // BRAND = brand;
        // COLOR = color;
        // NUMBEROFWHEEL = numberofwheel;       
        NUMBEROFSEAT = numberofseat;
        ENGINETYPE = enginetype;
    }
    // string getBrand();
    // string getColor();
    // int getNumberofwheel();
    // int getNumberofseat();
    // string getEnginetype();

    // void setBrand();
    // void setColor();
    // void setNumberofwheel();
    // void setNumberofseat();
    // void setEnginetype();
    
    void infor();
    string getType() const override {
        return "Automotive";
    }
};

class Motor : public Vehicle
{

public:
    Motor(string brand, string color, int numberofwheel) : Vehicle(brand, color, numberofwheel){
        BRAND = brand;
        COLOR = color;
        NUMBEROFWHEEL = numberofwheel;  
    }
    // string getBrand();
    // string getColor();
    // int getNumberofwheel();

    // void setBrand();
    // void setColor();
    // void setNumberofwheel();

    void infor();
    string getType() const override {
        return "Motor";
    }
};


    // vector<Vehicle*> database;
    

//==========================================================================================================================================================
// string Vehicle::getBrand(){
//     return BRAND;
// }

// string Vehicle::getColor(){
//     return COLOR;
// }

// int Vehicle::getNumberofwheel(){
//     return NUMBEROFWHEEL;
// }

// void Vehicle::setBrand(){
//     string brand;
//     cout << "Brand: ";
//     cin >> brand;
//     BRAND = brand;
// }

// void Vehicle::setColor(){
//     string color;
//     cout << "Color: ";
//     cin >> color;
//     COLOR = color;
// }

// void Vehicle::setNumberofwheel(){
//     int numberofwheel;
//     cout << "Number Of Wheels: ";
//     cin >> numberofwheel;
//     NUMBEROFWHEEL = numberofwheel;
// }

void Vehicle::infor() const{
    cout<<"-----------------------------------\n";
        cout<<"Brand: "<<BRAND<<endl;
        cout<<"Color: "<<COLOR<<endl;
        cout<<"Number Of Wheels: "<<NUMBEROFWHEEL<<endl;
}

//==========================================================================================================================================================

// string Automotive::getBrand(){
//     Vehicle::getBrand();
// }

// string Automotive::getColor(){
//     Vehicle::getColor();
// }

// int Automotive::getNumberofwheel(){
//     Vehicle::getNumberofwheel();
// }

// int Automotive::getNumberofseat(){
//     return NUMBEROFSEAT;
// }

// string Automotive::getEnginetype(){
//     return ENGINETYPE;
// }

// void Automotive::setBrand(){
//     Vehicle::setBrand();
// }

// void Automotive::setColor(){
//     Vehicle::setColor();
// }

// void Automotive::setNumberofwheel(){
//     Vehicle::setNumberofwheel();
// }

// void Automotive::setNumberofseat(){
//     int numberofseat;
//     cout << "Number Of Seats: ";
//     cin >> numberofseat;
//     NUMBEROFSEAT = numberofseat;
// }

// void Automotive::setEnginetype(){
//     string enginetype;
//     cout << "Engine Type: ";
//     cin >> enginetype;
//     ENGINETYPE = enginetype;
// }

void Automotive::infor(){
    Vehicle::infor();
    cout << "Number of Seats: " <<NUMBEROFSEAT << endl;
    cout << "Engine Type: " << ENGINETYPE << endl;

}

//========================================================================================================================================================================
// string Motor::getBrand(){
//     Vehicle::getBrand();
// }

// string Motor::getColor(){
//     Vehicle::getColor();
// }

// int Motor::getNumberofwheel(){
//     Vehicle::getNumberofwheel();
// }

// void Motor::setBrand(){
//     Vehicle::setBrand();
// }

// void Motor::setColor(){
//     Vehicle::setColor();
// }

// void Motor::setNumberofwheel(){
//     Vehicle::setNumberofwheel();
// }

void Motor::infor(){
    Vehicle::infor();
}

//============================================================================================================

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


int main(int argc, char const *argv[])
{
    vector<Vehicle*> database;

    while(1){
        int options;
        cout<<"---------------------------------------------------------"<<endl;
        cout<<"OPTIONS!"<<endl;
        cout << "1. Add Vehicle" << endl;
        cout << "2. Display Information" << endl;
        cin >> options;
        switch (options)
        {
        case 1:
        while (1){
            int ch1;
            cout << "1. Add Car\n2. Add Motor\n";
            cin >> ch1;
            if(ch1 == 1) {
                addCar(database);
                break;
            }
            else if (ch1 == 2) {
                addMotor(database);
                break;
            }
            else  cout << "Error! Please try again.\n";
        }

            break;
        case 2:
        while (1){
            int ch2;
            cout << "1. Car Infor\n2. Motor Infor\n3. All Vehicle Infor\n";
            cin >> ch2;
            if (ch2 == 1){
                displayAu(database);
                
            }
            else if (ch2 == 2){
                displayMo(database);
                
            }
            else if (ch2 == 3){
                displayAll(database);
                
            }
            else cout << "Error! Please try again.";
        }
            break;
        default:
            break;
        }
    }
    return 0;
}
