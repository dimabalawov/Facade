#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

bool randomSuccess() {
    return rand() % 2 == 0;
}

class ComputerDevice {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};

class VideoCard : public ComputerDevice {
public:
    void start() override {
        cout << "Video Card: Starting..." << endl;
        if (randomSuccess()) {
            cout << "Video Card: Started successfully." << endl;
        }
        else {
            cout << "Video Card: Failed to start!" << endl;
        }
    }

    void stop() override {
        cout << "Video Card: Stopping..." << endl;
        if (randomSuccess()) {
            cout << "Video Card: Stopped successfully." << endl;
        }
        else {
            cout << "Video Card: Failed to stop!" << endl;
        }
    }
};

class RAM : public ComputerDevice {
public:
    void start() override {
        cout << "RAM: Starting..." << endl;
        if (randomSuccess()) {
            cout << "RAM: Started successfully." << endl;
        }
        else {
            cout << "RAM: Failed to start!" << endl;
        }
    }

    void stop() override {
        cout << "RAM: Stopping..." << endl;
        if (randomSuccess()) {
            cout << "RAM: Stopped successfully." << endl;
        }
        else {
            cout << "RAM: Failed to stop!" << endl;
        }
    }
};


class HardDrive : public ComputerDevice {
public:
    void start() override {
        cout << "Hard Drive: Starting..." << endl;
        if (randomSuccess()) {
            cout << "Hard Drive: Started successfully." << endl;
        }
        else {
            cout << "Hard Drive: Failed to start!" << endl;
        }
    }

    void stop() override {
        cout << "Hard Drive: Stopping..." << endl;
        if (randomSuccess()) {
            cout << "Hard Drive: Stopped successfully." << endl;
        }
        else {
            cout << "Hard Drive: Failed to stop!" << endl;
        }
    }
};


class OpticalDrive : public ComputerDevice {
public:
    void start() override {
        cout << "Optical Drive: Starting..." << endl;
        if (randomSuccess()) {
            cout << "Optical Drive: Started successfully." << endl;
        }
        else {
            cout << "Optical Drive: Failed to start!" << endl;
        }
    }

    void stop() override {
        cout << "Optical Drive: Stopping..." << endl;
        if (randomSuccess()) {
            cout << "Optical Drive: Stopped successfully." << endl;
        }
        else {
            cout << "Optical Drive: Failed to stop!" << endl;
        }
    }
};


class PowerSupply : public ComputerDevice {
public:
    void start() override {
        cout << "Power Supply: Providing power..." << endl;
        if (randomSuccess()) {
            cout << "Power Supply: Power provided successfully." << endl;
        }
        else {
            cout << "Power Supply: Failed to provide power!" << endl;
        }
    }

    void stop() override {
        cout << "Power Supply: Cutting power..." << endl;
        if (randomSuccess()) {
            cout << "Power Supply: Power cut successfully." << endl;
        }
        else {
            cout << "Power Supply: Failed to cut power!" << endl;
        }
    }
};

class Sensors : public ComputerDevice {
public:
    void checkVoltage() {
        cout << "Sensors: Checking voltage..." << endl;
        if (randomSuccess()) {
            cout << "Sensors: Voltage checked successfully." << endl;
        }
        else {
            cout << "Sensors: Failed to check voltage!" << endl;
        }
    }

    void checkTemperature() {
        cout << "Sensors: Checking temperature..." << endl;
        if (randomSuccess()) {
            cout << "Sensors: Temperature checked successfully." << endl;
        }
        else {
            cout << "Sensors: Failed to check temperature!" << endl;
        }
    }

    void start() override {
        checkVoltage();
        checkTemperature();
    }

    void stop() override {
        cout << "Sensors: Shutting down..." << endl;
        if (randomSuccess()) {
            cout << "Sensors: Shutdown successful." << endl;
        }
        else {
            cout << "Sensors: Failed to shutdown!" << endl;
        }
    }
};

class ComputerFacade {
private:
    VideoCard* videoCard;
    RAM* ram;
    HardDrive* hardDrive;
    OpticalDrive* opticalDrive;
    PowerSupply* powerSupply;
    Sensors* sensors;

public:
    ComputerFacade() {
        videoCard = new VideoCard();
        ram = new RAM();
        hardDrive = new HardDrive();
        opticalDrive = new OpticalDrive();
        powerSupply = new PowerSupply();
        sensors = new Sensors();
    }

    ~ComputerFacade() {
        delete videoCard;
        delete ram;
        delete hardDrive;
        delete opticalDrive;
        delete powerSupply;
        delete sensors;
    }

    void beginWork() {
        powerSupply->start();
        sensors->start();
        videoCard->start();
        ram->start();
        opticalDrive->start();
        hardDrive->start();
        sensors->stop();
    }

    void endWork() {
        hardDrive->stop();
        ram->stop();
        videoCard->stop();
        opticalDrive->stop();
        powerSupply->stop();
    }
};

int main() {
    srand(time(0));
    ComputerFacade computer;

    cout << "Starting computer..." << endl;
    computer.beginWork();

    cout << endl;
    cout << "Shutting down computer..." << endl;
    computer.endWork();

    return 0;
}
