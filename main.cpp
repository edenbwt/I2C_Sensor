#include "sensor.h"
#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    
    
    MCP9808Sensor sensor(0x18);
    
    if (sensor.init() == false){
        cout << "Error initialisation sensor";
        return 0;
    }
    
    cout << "initialisation sensor fonctionnelle !!!!\n";
    
    while (true == true) {
    sensor.displayTemperature();
    sleep(5);
}
    return 0;
    
    
    
    
    
    }
