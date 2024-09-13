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
    std::cout << "I2C communication successfully setup.\n";
    return fd;
}

int ReadTemp(int fd){
    int temprequest = wiringPiI2CReadReg16(fd, MCP9808_REG_AMBIENT_TEMP);
    
    if (temprequest == -1){
        std::cerr << "Error read temp from sensor.\n";
        return -1;
    }
    
    
    return temprequest;
}
    
    
    
    
    
int main(){
    if (initMCP9808() == -1){

        std::cout << " Error I2C bus inithilision\n";
        return -1;
    }else{
    
        std::cout << " work I2C bus good \n";
    
    }
    
    int fd = initMCP9808();
    if (fd == -1){
        std::cerr << "Error initMCP9808\n";
        return -1;
    }
    int temp = ReadTemp(fd);
    
    std::cout << temp << "\n";
    int data = ((temp & 0xff) << 8 | (temp & 0xff00) >> 8);
    std::cout << data << "\n";
    data = (data & 0x0fff);
    std::cout << data << "\n";
    data = (data / 16.0);
    std::cout << data << "\n";
    return 0;

}
