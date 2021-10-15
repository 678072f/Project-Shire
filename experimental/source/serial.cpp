// Serial Communications Link V1.0
// Daniel Duhon, 10/14/2021
// Serial Class

#include <stdlib.h>
#include "serial.h"

using namespace Shire;

Serial::Serial(void) {
    // Constructor: Setup serial connection here.
    std::cout << "Object is being created.\n";
}

double Serial::readSerial(void) {
    // Read data from serial port and store to variable.
    std::cout << "Do stuff...\n";
    return data;
}

void Serial::writeSerial(double data, std::string dataString) {
    // Write data to serial.
    std::cout << "Do stuff...\n";
    serialData = data;
    serialDataString = dataString;
}

Serial::~Serial() {
    // Destructor: Uninitialize serial connection here.
    std::cout << "Object is being deleted.\n";
}
