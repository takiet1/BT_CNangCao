#ifndef __MOTOR_H
#define __MOTOR_H

#include <iostream>
#include <Vehicle.h>
#include <Automotive.h>

using namespace std;

class Motor : public Vehicle
{

public:
    Motor(string brand, string color, int numberofwheel) : Vehicle(brand, color, numberofwheel){}
    

    void infor();
    string getType() const override {
        return "Motor";
    }
};

#endif