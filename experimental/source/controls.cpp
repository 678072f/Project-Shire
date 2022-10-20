// Controls Class v1.0
// Daniel Duhon, 10/20/2022
// Controls Class

// Included files
#include "controls.h"

// Define control surface paths
#define ARDUINO1 "/dev/ttyAMA0"
#define ARDUINO2 "/dev/ttyAMA1"
#define ARDUINO3 "/dev/ttyAMA2"

// Initialize Serial Class
Shire::Serial elevators(ARDUINO1);
Shire::Serial ailerons(ARDUINO1);
Shire::Serial rudder(ARDUINO2);
Shire::Serial flaps(ARDUINO2);
Shire::Serial throttle(ARDUINO3);

// Controls self-test
Controls::Controls() {
    std::cout << "Hello World!\n";
    elevators.openSerialPort();
    rudder.openSerialPort();
    throttle.openSerialPort();
}

// Read the control input and store it to controlInput
double Controls::readControlInput() {
    
    return 0;
}

// Set the amount of delflection from controlInput to deflection
void Controls::setDeflection(double delta) {
    
}

// Read the deflection variable
double getDeflection() {
    
    return 0;
}

// Clean up program upon shutdown
Controls::~Controls() {
    std::cout << "Bye bye!\n";
}
