#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class NavigationSystem
{
private:
    const vector<vector<ParkingSlot>> &parkingMap; //Danh sach vi tri đỗ
    Position currentPos;            //Vi tri bat dau
    VehicleType VEHICLE_TYPE;       //Loai phương tiện
public:
    ParkingSlot &destination;       
    
    NavigationSystem(ParkingSlot& destination, 
            const vector<vector<ParkingSlot>>& parkingSlots, 
            VehicleType vehicleType, Position startPos) : 
            destination(destination), 
            parkingMap(parkingSlots), 
            VEHICLE_TYPE(vehicleType), 
            currentPos(startPos){}
    //Tinh toan lo trinh 
    vector<Position> calculateRoute();
    //huong dan di chuyen
    void guideMovement(ParkingSlot& destination);
    //Set vi tri hien tai
    void setCurrentPossition(Position pos);
    //Get vi tri hien tai
    Position getCurrentPosition();
    void getmap();
    // Lấy giá trị của position của destination
    // Position getDestinationPosition();
    double getDistance();
    int getMoveDistance(int distance);
    
};

class ParkingLot {
    private:
        vector<vector<ParkingSlot>> slots;
        int distance; //Khoang cach giua cac vi tri

    public:
        ParkingLot(vector<vector<ParkingSlot>> slots, int distance) : slots(slots), distance(distance) {}

        //Lay ra tong vi tri con trong
        int checkAvailableSlots();
        //Cap nhat vi tri do
        bool updateSlotStatus(const Position& pos, bool status);
        //lay ra tong vi tri
        int getTotalSlots();
        //Lay vi tri giua hai cho do xe
        int getDistance();
        //Lay thong tin tai vi tri
        int getInforSlot();
        //Lay ra bai dau xe
        vector<vector<ParkingSlot>> &getSlots() { return slots;}
        // static ParkingLot& getInstance() {
        //     static ParkingLot distance;
        //     return distance;
        // }
        
};

class Dimensions
{
private:
    float length;
    float width;
public:
    Dimensions(float l, float w) : length(l), width(w) {};

    float getLength();
    float getWidth();
};

typedef enum{   //se Code o file vehicle.h
    MOTOBIKE,
    CAR, 
    bike
} VehicleType;

class ParkingSlot
{
private:
    Dimensions Slotsize;
public:
    bool isOccupied;        //Trạng thái vị trí đỗ
    VehicleType slotType;   //Loại vị trí(xe máy, ô tô, ...)
    int slotNumber;         //STT của xe đó

    ParkingSlot(VehicleType type, int number, Dimensions size) : isOccupied(false), slotType(type), slotNumber(number), Slotsize(size) {};

    bool checkStatus();
    void updateStatus(bool status);
    VehicleType getSlotType();
    int getSlotNumber();
    Dimensions getSize();
};

struct Position{
    int x, y;
    Position (int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(Position &other){
        return x == other.x && y == other.y;
    }
};

class Vehicle
{
    private:
        string licensePlate; //Bien so xe
        //Dimensions SIZE;
        VehicleType type;
    public:
        Vehicle(VehicleType vehicleType, string license) : type(vehicleType), licensePlate(license){};

        string getLicensePlate();
        void setLicensePlate(string license);
        // Dimensions getSize();

        //Tim vi tri trong gan nhat
        ParkingSlot* findParkingSlot(vector<vector<ParkingSlot>> parkingSlots);
        //Phuong thuc di chuyen
        //bool nagitive(ParkingSlot *slot);
        //Phuong thuc do xe
        bool park(ParkingSlot *slot);
        VehicleType getVehicleType();
};

////////////////////////////////////////////////////////////
int count = 0;

double NavigationSystem::getDistance() {

}
int NavigationSystem::getMoveDistance(int distance) {
    int totalDistance = count * distance;
    return totalDistance;
}

//Set vi tri hien tai
void NavigationSystem::setCurrentPossition(Position pos) {
    currentPos = pos;
}
//Get vi tri hien tai
Position NavigationSystem::getCurrentPosition(){
    return currentPos;
}
void NavigationSystem::getmap(){
    int numRows = parkingMap.size(); // Số hàng
    int numCols = (numRows > 0) ? parkingMap[0].size() : 0;

    int suitable = destination.slotNumber;
    int row = (suitable - 1) / numCols;
    int col = (suitable - 1) % numCols;

    for (int i = 0; i < parkingMap.size(); i++) {
        for (int j = 0; j < parkingMap[i].size(); j++) {
            if (row == i && col == j)
                cout << "T "; // Vị trí đích đến
            else if (parkingMap[i][j].isOccupied)
                cout << "1 "; // Đã chiếm chỗ đỗ
            else if (parkingMap[i][j].slotType != VEHICLE_TYPE)
                cout << "x "; // Loại xe khác
            else
                cout << "0 "; // Còn trống
        }
        cout << endl;
    }
}

//test
void NavigationSystem::guideMovement(ParkingSlot& destination) {

    int targetPosx = -1;
    int targetPosy = -1;
    
    int numRows = parkingMap.size(); // Số hàng
    int numCols = (numRows > 0) ? parkingMap[0].size() : 0;

    int suitable = destination.slotNumber;
    int row = (suitable - 1) / numCols;
    int col = (suitable - 1) % numCols;
    for (int i = 0; i < parkingMap.size(); i++) {
        for (int j = 0; j < parkingMap[i].size(); j++) {
            if (row == i && col == j)
            {
                targetPosx=i;
                targetPosy=j;
            }
        }
    }
    Position targetPos;
    targetPos.x = targetPosx;
    targetPos.y = targetPosy;

    vector<string> directions;
    int currentX = currentPos.x;
    int currentY = currentPos.y;
    cout << "Begin pos: " << currentPos.x << " " << currentPos.y << endl;
    cout << "Target pos: " << targetPos.x << " " << targetPos.y << endl;
     
    while (currentPos.x != targetPos.x || currentPos.y != targetPos.y) {
        
        if (currentPos.x < targetPos.x) {
            count++;
            currentPos.x += 1;
            cout <<"turn down:  "<<"("<<currentPos.x<<", "<<currentPos.y<<")"<<endl;
        }
        else if (currentPos.x > targetPos.x) {
            count++;
            currentPos.x -= 1;
            cout <<"turn up:    "<<"("<<currentPos.x<<", "<<currentPos.y<<")"<<endl;
        }
        if (currentPos.y < targetPos.y) {
            count++;
            currentPos.y += 1;
            cout <<"turn right: "<<"("<<currentPos.x<<", "<<currentPos.y<<")"<<endl;
        }
        else if (currentPos.y > targetPos.y) {
            count++;
            currentPos.y -= 1;
            cout <<"turn left:  "<<"("<<currentPos.x<<", "<<currentPos.y<<")"<<endl;
        }
    }
    
}

int ParkingLot::checkAvailableSlots(){
    int availableCount = 0;
        for (const vector<ParkingSlot>& row : slots) {
            for (const ParkingSlot& slot : row) {
                if (!slot.isOccupied) {
                    availableCount++;
                }
            }
        }
        return availableCount;
}
bool ParkingLot::updateSlotStatus(const Position& pos, bool status){
    int row = pos.x;
    int col = pos.y;

    if (row >= 0 && row < slots.size() && col >= 0 && col < slots[row].size()) {
        slots[row][col].isOccupied = status;
        return true;
    }
    return false;
}
int ParkingLot::getTotalSlots(){
    int total = 0;
    for (const vector<ParkingSlot>& row : slots) {
        total += row.size();
    }
    return total;
}
int ParkingLot::getDistance(){
    return distance;
}
//////////////////////////////////////////////////////////////////////////////////

int ParkingLot::checkAvailableSlots(){
    int availableCount = 0;
        for (const vector<ParkingSlot>& row : slots) {
            for (const ParkingSlot& slot : row) {
                if (!slot.isOccupied) {
                    availableCount++;
                }
            }
        }
        return availableCount;
}
bool ParkingLot::updateSlotStatus(const Position& pos, bool status){
    int row = pos.x;
    int col = pos.y;

    if (row >= 0 && row < slots.size() && col >= 0 && col < slots[row].size()) {
        slots[row][col].isOccupied = status;
        return true;
    }
    return false;
}
int ParkingLot::getTotalSlots(){
    int total = 0;
    for (const vector<ParkingSlot>& row : slots) {
        total += row.size();
    }
    return total;
}
int ParkingLot::getDistance(){
    return distance;
}

////////////////////////////////////////////////////////////////////////////////////////////////

float Dimensions::getLength(){
    return length;
}
float Dimensions::getWidth(){
    return width;
}
//=============================================================ParkingSlot
bool ParkingSlot::checkStatus(){
    return isOccupied;
}
void ParkingSlot::updateStatus(bool status){
    isOccupied = status;
}
VehicleType ParkingSlot::getSlotType(){
    return slotType;
}
int ParkingSlot::getSlotNumber(){
    return slotNumber;
}
Dimensions ParkingSlot::getSize(){
    return Slotsize;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

string Vehicle::getLicensePlate(){
    return licensePlate;
}
void Vehicle::setLicensePlate(string license){
    licensePlate = license;
}
// Dimensions Vehicle::getSize(){
//     return SIZE;
// }
ParkingSlot* Vehicle::findParkingSlot(vector<vector<ParkingSlot>> parkingSlots){
    for (const vector<ParkingSlot>& row : parkingSlots) {
        for (const ParkingSlot& slot : row) {
            if (!slot.isOccupied && slot.slotType == getVehicleType()) {
                cout << "Position suitable Slot: "<<slot.slotNumber << endl;
                return const_cast<ParkingSlot*>(&slot);
            }
        }
    }
    return nullptr;
}
// bool Vehicle::nagitive(ParkingSlot *slot){
// }
bool Vehicle::park(ParkingSlot *slot){
}
// string Vehicle::getVehicalType(){
//     string type_name = "";
//     if(type == 1) type_name ="CAR";
//     else if( type == 0) type_name="Motobike";
//     return type_name;
// }

VehicleType Vehicle::getVehicleType(){
    return type;
}

int main(int argc, char const *argv[])
{
    //Tao ra 9 vi tri do xe
    vector <vector<ParkingSlot>> slots = {
        {ParkingSlot(MOTOBIKE, 1, Dimensions(2.5, 1)), ParkingSlot(bike, 2, Dimensions(2.5, 1)), ParkingSlot(MOTOBIKE, 3, Dimensions(2.5, 1))},
        {ParkingSlot(CAR, 4, Dimensions(6.8, 4.5)), ParkingSlot(CAR, 5, Dimensions(6.8, 4.5)), ParkingSlot(CAR, 6, Dimensions(6.8, 4.5))},
        {ParkingSlot(CAR, 7, Dimensions(6.8, 4.5)), ParkingSlot(CAR, 8, Dimensions(6.8, 4.5)), ParkingSlot(CAR, 9, Dimensions(6.8, 4.5))}
    };
    //=================================================Test ParkingSlot=====================================
    // ParkingSlot carslot(CAR, 5, Dimensions(2.5, 1));
    // cout<<"Position: "<< carslot.getSlotNumber() <<endl;
    // if(carslot.getSlotType() == CAR)
    //     cout << "Car\n";
    // else if(carslot.getSlotType() == MOTOBIKE)
    //     cout << "MOTOBIKE\n";
    // cout << (carslot.checkStatus() ? "Dang duoc chiem\n" : "Dang trong") << endl;
    // carslot.updateStatus(true);
    // cout << (carslot.checkStatus() ? "Dang duoc chiem\n" : "Dang trong") << endl;
    //=================================================Test Parkinglot=====================================
    //Tao 1 bai do xe gom cac vi tri tren, gia su moi vi tri cach nhau 10m
    ParkingLot parkingLot(slots,5);
    // cout << "Distance: "<<parkingLot.getDistance() << endl;
    // cout << "Total slot: " << parkingLot.getTotalSlots() << endl;
    // cout << "So slot con trong: " << parkingLot.checkAvailableSlots() << endl;
    //Gia su update vi tri 1,0 va 1,1
    parkingLot.updateSlotStatus(Position(1,0), false);
    parkingLot.updateSlotStatus(Position(1,1), true);
    // cout << "So slot con trong: " << parkingLot.checkAvailableSlots() << endl;
    //=================================================Test Vehicle=====================================
    //Tao 1 car
    Vehicle myVehicle(CAR, "abc123");
    // cout << "VehicleType: " << myVehicle.getVehicalType() << endl;
    // cout << "LicensePlate: " << myVehicle.getLicensePlate() << endl;
    //Lay ra cac vi tri trong bai dau xe
    vector<vector<ParkingSlot>> slotOfParkingLot = parkingLot.getSlots();
    //Test check getSlots Success
    // for (const vector<ParkingSlot>& row : slotOfParkingLot) {
    //     for (const ParkingSlot& slot : row) {
    //         // In các thông tin về vị trí đỗ xe (các thuộc tính của ParkingSlot) bằng cout
    //         cout << "Slot Type: " << slot.slotType << ", Occupied: " << slot.isOccupied << ", Slot Number: " << slot.slotNumber << ", ... " << endl;
    //     }
    // }
    //Tim cho do tuong ung voi loai phuong tien va kiem tra trang thai con trong
    ParkingSlot *suitableSlot = myVehicle.findParkingSlot(slotOfParkingLot);
    //suitableSlot Nhan gia tri thanh cong

    if(suitableSlot){
        //Da tim thay vi tri do gan nhat
        cout << "Nearest vacant position found" << endl;
        
        //Vi tri ban dau (x,y)
        NavigationSystem navigationSystem(*suitableSlot, slotOfParkingLot, myVehicle.getVehicleType(), Position(2,2));
        cout << "Destination Position:" << navigationSystem.destination.getSlotNumber() << endl;
        //Hien thi map
        //T: vi tri can den
        //x: vi tri loai xe khac
        //1: da chiem cho
        //0: còn trống
        
        cout << "map of the packing lot" << endl;
        navigationSystem.getmap();

        //huong dan duong di
        cout << " direction to the packing location " << endl;
        navigationSystem.guideMovement(*suitableSlot);
        cout << " Distance away: " << navigationSystem.getMoveDistance(parkingLot.getDistance()) << "(m)" << endl;
    }
    else{
        cout << "Khong tim thay vi tri phu hop\n";
    }
}