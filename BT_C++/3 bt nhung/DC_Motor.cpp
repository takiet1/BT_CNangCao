#include <iostream>

class DCMotor {
private:
    float voltage;
    float maxCurrent;
    float speed;
    std::string direction;
    bool isRunning;

public:
    DCMotor(float v, float current) {
        voltage = v;
        maxCurrent = current;
        speed = 0.0f;
        direction = "STOP";
        isRunning = false;
    }

    void setSpeed(float s) {
        if (s >= 0 && s <= 100) {
            speed = s;
            if (speed > 0)
                isRunning = true;
            else
                isRunning = false;
        }
    }

    void setDirection(std::string dir) {
        if (dir == "CLOCKWISE" || dir == "COUNTERCLOCKWISE") {
            direction = dir;
        }
    }

    void start() {
        if (isRunning) {
            std::cout << "The motor is already running." << std::endl;
        } else {
            isRunning = true;
            std::cout << "Motor started." << std::endl;
        }
    }

    void stop() {
        if (!isRunning) {
            std::cout << "The motor is already stopped." << std::endl;
        } else {
            isRunning = false;
            std::cout << "Motor stopped." << std::endl;
        }
    }

    void printStatus() {
        std::cout << "Motor Status:" << std::endl;
        std::cout << "Voltage: " << voltage << " V" << std::endl;
        std::cout << "Max Current: " << maxCurrent << " A" << std::endl;
        std::cout << "Speed: " << speed << std::endl;
        std::cout << "Direction: " << direction << std::endl;
        std::cout << "Motor is " << (isRunning ? "running" : "stopped") << std::endl;
    }

    float getSpeed() const {
        return speed;
    }
};

class FeedbackSystem {
public:
    bool isOverloadDetected(float speed) {
        if (speed > 100) {
            return true;
        }
        return false;
    }

    bool isOverheatDetected() {
        // 
        return false;
    }
};

class DCMotorController {
private:
    DCMotor motor;
    FeedbackSystem feedback;

public:
    DCMotorController(float voltage, float maxCurrent)
        : motor(voltage, maxCurrent) {}

    void controlMotor(float speed, std::string direction) {
        motor.setSpeed(speed);
        motor.setDirection(direction);

        if (feedback.isOverloadDetected(speed) || feedback.isOverheatDetected()) {
            std::cout << "Motor is overload !" << std::endl;
            motor.stop();
        } else {
            motor.start();
        }
    }
    DCMotor& getMotor(){
        return motor;
    }
};

int main() {
    float voltage, maxCurrent;
    std::cout << "Enter voltage: ";
    std::cin >> voltage;
    std::cout << "Enter max current: ";
    std::cin >> maxCurrent;

    DCMotorController controller(voltage, maxCurrent);

    float speed;
    std::string direction;

    while (true) {
        std::cout << "Enter speed (0-100, -1 to exit): ";
        std::cin >> speed;

        if (speed == -1)
            break;

        std::cout << "Enter direction (CLOCKWISE or COUNTERCLOCKWISE): ";
        std::cin >> direction;

        controller.controlMotor(speed, direction);
        controller.getMotor().printStatus();
    }

    return 0;
}