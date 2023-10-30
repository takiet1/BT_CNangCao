#ifndef __FUNCTION_H
#define __FUNCTION_H

#include <iostream>
#include <vector>
#include <Vehicle.h>
#include <Automotive.h>
#include <Motor.h>

using namespace std;

void addCar(vecto<Vehicle*> &database);
void addMotor(vecto<Vehicle*> &database);
void displayAu(vecto<Vehicle*> &database);
void displayMo(vecto<Vehicle*> &database);
void displayAll(vecto<Vehicle*> &database);

#endif