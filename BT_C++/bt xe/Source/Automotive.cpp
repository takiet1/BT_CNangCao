#include <Automotive.h>

void Automotive::infor(){
    Vehicle::infor();
    cout << "Number of Seats: " <<NUMBEROFSEAT << endl;
    cout << "Engine Type: " << ENGINETYPE << endl;

}
