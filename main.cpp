#include <iostream>
#include <wiringPiI2C.h>
#include <unistd.h>

#define MCP9808_ADDRESS 0x18

#define MCP9808_REG_AMBIENT_TEMP 0x05

int initMCP9808() {
    int fd = wiringPiI2CSetup(MCP9808_ADDRESS);

    if (fd == -1) {
        std::cerr << "Failed to initialize I2C communication.\n";
        return -1;
    }
    std::
    cout << "I2C communication successfully setup.\n";
    return fd;
}

void main(){
    initMCP9808();

}