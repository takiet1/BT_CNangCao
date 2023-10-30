#ifndef __VEHICLE_H
#define __VEHICLE_H

#include <iostream>

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

    virtual void infor() const;
    virtual string getType() const = 0;
};

#endif