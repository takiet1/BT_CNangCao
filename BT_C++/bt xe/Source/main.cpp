#include <iostream>
#include <vector>
#include <Vehicle.h>
#include <Automotive.h>
#include <Motor.h>
#include <Function.h>

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

