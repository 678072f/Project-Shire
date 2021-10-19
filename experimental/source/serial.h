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
        void openSerialPort(); // Open the serial port.
        void readSerial(); // Public Read from serial function
        void writeSerial(char data); // Public write to serial function
        void setSerialPort(char * port); // allows for modifying the serial port
        char getSerialData(); // Retrieve whatever is stored in "serialDataIn" from reading
        int getNumberRead(); // Read how many bytes were received
        ~Serial(); // Destructor
    private:
        char * serialPortDir;
        int serialPort; // Serial port
        struct termios arduino;
        int numberRead;
        char serialDataOut; // Data to write to serial.
        char serialDataIn[]; // Data read from serial.
    };
}

#endif
