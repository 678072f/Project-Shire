// Serial UART Class V1.1
// Daniel Duhon, 10/19/2021
// Serial Class

#ifndef SERIAL_H
#define SERIAL_H

// Included libraries
#include <stdlib.h> // Standard Library for printf
#include <iostream> // For inputs and outputs
#include <stdio.h> // Standard input and ouput library
#include <fcntl.h> // File controls (Linux/UNIX)
#include <errno.h> // Error functions
#include <termios.h> // POSIX Terminal control definitions
#include <unistd.h> // write(), read(), close()
#include <string.h>

// Define Shire namespace
namespace Shire {
// Define Serial class
    class Serial {
    public:
        Serial(char * serial); // Constructor
        void openSerialPort(); // Open the serial port.
        char readSerial(); // Public Read from serial function
        void writeSerial(char data); // Public write to serial function
        char getSerialData(); // Retrieve whatever is stored in "serialDataIn" from reading
        int getNumberRead(); // Read how many bytes were received
        ~Serial(); // Destructor
    private:
        char * serialPortDir;
        int serialPort; // Serial port
        int numberRead;
        char serialDataOut; // Data to write to serial.
        char serialDataIn[]; // Data read from serial.
    };
}

#endif
