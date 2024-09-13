#include "sensor.h"
#include <iostream>
#include <wiringPiI2C.h>
#include <unistd.h>

#define MCP9808_REG_AMBIENT_TEMP 0x05

// Constructor to initialize the sensor with an I2C address
MCP9808Sensor::MCP9808Sensor(int addr) : address(addr), fd(-1), temperature(0.0) {}

// Method to initialize I2C communication
bool MCP9808Sensor::init() {
    fd = wiringPiI2CSetup(address);
    if (fd == -1) {
        std::cerr << "Failed to initialize I2C communication.\n";
        return false;
    }
    std::cout << "I2C communication successfully set up.\n";
    return true;
}

// Method to read temperature from the sensor
float MCP9808Sensor::getTemperature() {
    int rawTemp = wiringPiI2CReadReg16(fd, MCP9808_REG_AMBIENT_TEMP);

    if (rawTemp == -1) {
        std::cerr << "Error reading temperature from sensor.\n";
        return -1;
    }

    // Swap bytes to handle endianness
    int temp = ((rawTemp & 0xff) << 8 | (rawTemp & 0xff00) >> 8);
    temp &= 0x0FFF;  // Mask out the flag bits
    temperature = temp / 16.0;  // Convert to Celsius
    return temperature;
}

// Method to display the current temperature
void MCP9808Sensor::displayTemperature() {
    float temp = getTemperature();
    if (temp != -1) {
        std::cout << "Current Temperature: " << temp << " °C\n";
    }
}

// Destructor (optional)
MCP9808Sensor::~MCP9808Sensor() {
    // Cleanup if necessary
}
