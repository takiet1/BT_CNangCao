#include <iostream>
#include <cmath>
#include <list>
#define EARTH_RADIUS 6371
#define PI 3.14159265359
using namespace std;

class GPSPoint {
    private:
        double LATITUDE, LONGITUDE;
    public:
        
        void input(double latitude, double longitude);
        bool isValid();
        double getLatitude();
        void setLatitude();
        double getLongitude();
        void setLongitude();
        double toRadians(double degree);
        double distanceTo(GPSPoint point1);
};
    double GPSPoint::getLatitude(){
        return LATITUDE;
    }
    double GPSPoint::getLongitude(){
        return LONGITUDE;
    }
    // void GPSPoint::setLatitude(){
    //     double latitude;
    //     cout << "Enter Latitude: ";
    //     cin >> latitude;
    //     LATITUDE = latitude;
    // }
    // void GPSPoint::setLongitude(){
    //     double longitude;
    //     cout << "Enter Longitude: ";
    //     cin >> longitude;
    //     LONGITUDE = longitude;
    // }
    bool GPSPoint::isValid() {
        return (getLatitude() >= -90 && getLatitude() <= 90) &&
               (getLongitude() >= -180 && getLongitude() <= 180);
    }
    void GPSPoint::input(double latitude, double longitude){
        LATITUDE = latitude;
        LONGITUDE = longitude;
    }

    double GPSPoint::toRadians(double degree){
        return (degree * (PI / 180));
    }
    double GPSPoint::distanceTo(GPSPoint point1){
        double latA = getLatitude();
        double lonA = getLongitude();

        double latB = point1.getLatitude();
        double lonB = point1.getLongitude();

        double dLat = toRadians(latB - latA);
        double dLon = toRadians(lonB - lonA);
        
        double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2)*cos(toRadians(latA))*cos(toRadians(latB));
        double c = 2 * asin(sqrt(a));
        return EARTH_RADIUS * c;
        
    }



int main(int argc, char const *argv[])
{
   GPSPoint pointA, pointB;
   double latitude, longitude;


    do {
        cout << "Enter coordinate of point A:\n";
        cout << "Enter Latitude: ";
        cin >> latitude;
        cout << "Enter Longitude: ";
        cin >> longitude;
        pointA.input(latitude, longitude);

    }while (!pointA.isValid());

    do {
        cout << "Enter coordinate of point B:\n";
        cout << "Enter Latitude: ";
        cin >> latitude;
        cout << "Enter Longitude: ";
        cin >> longitude;
        pointB.input(latitude, longitude);

    }while (!pointB.isValid());
    

    cout << "Distance of A and B: " << pointA.distanceTo(pointB) << endl; 

    
    return 0;
}
