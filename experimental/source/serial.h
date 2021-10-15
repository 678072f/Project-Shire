// Serial UART Class V1.0
// Daniel Duhon, 10/14/2021
// Serial Class

#ifndef SERIAL_H
#define SERIAL_H

#include <iostream>
#include <string>

namespace Shire {
    class Serial {
    public:
        Serial(); // Constructor
        double readSerial(void); // Public Read from serial function
        void writeSerial(double data, std::string dataString); // Public write to serial function
        ~Serial(); // Destructor
    private:
        double serialData; // Data stored from serial.
        std::string serialDataString;
    }
}

#endif
