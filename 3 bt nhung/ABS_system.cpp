#include <iostream>

class Wheel {
private:
    double rotationSpeed; // Tốc độ quay của bánh xe (vòng/phút)

public:
    void setRotationSpeed(double speed) {
        rotationSpeed = speed;
    }

    double getRotationSpeed() const {
        return rotationSpeed;
    }
};

class Car {
private:
    Wheel wheel;
    double baseWeight; // Khối lượng cơ bản của xe (kg)
    double totalWeight; // Tổng khối lượng của xe (kg)

public:
    Car() {
        baseWeight = 1000.0;
        totalWeight = baseWeight;
    }

    void setWeight(double weight) {
        totalWeight = baseWeight + weight;
    }

    double getTotalWeight() const {
        return totalWeight;
    }

    void addPassenger(double weight) {
        totalWeight += weight;
    }

    Wheel& getWheel() {
        return wheel;
    }
};

class ABS {
private:
    Car& car;

public:
    ABS(Car& c) : car(c) {}

    void applyBrake() {
        double currentSpeed = car.getWheel().getRotationSpeed();

        if (currentSpeed < 10.0) {
            std::cout << "Warning! The wheels are at risk of locking\n";
            
        }
        else {
            std::cout << "Brakes are applied normally.\n";
        }
    }
};

int main() {
    Car car;
    ABS abs(car);

    double weight;

    std::cout << "Set the rotation speed for the wheel: ";
    double speed;
    std::cin >> speed;
    car.getWheel().setRotationSpeed(speed);

    abs.applyBrake();

    std::cout << "Add a passenger (enter mass):";
    std::cin >> weight;
    car.addPassenger(weight);

    std::cout << "Set the rotation speed for the wheel: ";
    std::cin >> speed;
    car.getWheel().setRotationSpeed(speed);
    std::cout << car.getTotalWeight() << endl;;
    abs.applyBrake();

    return 0;
}