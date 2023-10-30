#ifndef __AUTOMOTIVE_H
#define __AUTOMOTIVE_H

#include <iostream>
#include <Vehicle.h>

using namespace std;

class Automotive : public Vehicle
{
private:
    int NUMBEROFSEAT;
    string ENGINETYPE;
public:
    
    Automotive(string brand, string color, int numberofwheel, int numberofseat, string enginetype) : Vehicle(brand, color, numberofwheel){
            
        NUMBEROFSEAT = numberofseat;
        ENGINETYPE = enginetype;
    }
    
    void infor();
    string getType() const override {
        return "Automotive";
    }
};

#endif 