#ifndef SENSOR_H
#define SENSOR_H

class MCP9808Sensor {
private:
    int address;
    int fd;
    float temperature;

public:
    // Constructor to initialize the sensor with an I2C address
    MCP9808Sensor(int addr);

    // Method to initialize I2C communication
    bool init();

    // Method to read temperature from the sensor
    float getTemperature();

    // Method to display the current temperature
    void displayTemperature();

    // Destructor (optional)
    ~MCP9808Sensor();
};

#endif
