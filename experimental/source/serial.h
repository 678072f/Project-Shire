// Serial UART Class V1.0
// Daniel Duhon, 10/14/2021
// Serial Class

#ifndef SERIAL_H
#define SERIAL_H

#include <iostream> // For inputs and outputs
#include <string> // For C++ Strings
#include <stdio.h> // Standard input and ouput library
#include <fcntl.h> // File controls (Linux/UNIX)
#include <errno.h> // Error functions
#include <termios.h> // POSIX Terminal control definitions
#include <unistd.h> // write(), read(), close()

namespace Shire {
    class Serial {
    public:
        Serial(); // Constructor
        double readSerial(void); // Public Read from serial function
        void writeSerial(double data, std::string dataString); // Public write to serial function
        ~Serial(); // Destructor
    private:
        int serialPort;
        double serialData; // Data stored from serial.
        std::string serialDataString;
    }
}

#endif
