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
        void setSerialPort(int port); // allows for modifying the serial port
        ~Serial(); // Destructor
    private:
        int serialPort; // Serial port (generally /dev/ttyACM0 for Arduino.
        double serialData; // Numerical data stored from serial (May not be correct).
        std::string serialDataString; // String data from serial (may not be correct).
        struct termios arduino;
    }
}

#endif
