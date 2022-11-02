// Serial UART Class V2.0
// Daniel Duhon, 10/21/2022
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

        // Interact with I/O variables
        void setElevatorDeflection(double deltaE);
        double getElevatorDeflection();
        void setAileronDeflection(double deltaA);
        double getAileronDeflection();
        void setRudderDeflection(double deltaR);
        double getRudderDeflection();
        void setThrottle(double deltaT);
        double getThrottle();

        // Get status messages
        bool checkElevatorStatus();
        bool checkAileronStatus();
        bool checkRudderStatus();
        bool checkThrottleStatus();

        ~Serial(); // Destructor
    private:
        // Serial Variables
        char * serialPortDir;
        int serialPort; // Serial port
        int numberRead;
        char serialDataOut; // Data to write to serial.

        // Input/Output variables
        double elevator_deflection;
        double aileron_deflection;
        double rudder_deflection;
        double throttle_setting;

        // Status variables
        bool elevatorStatus;
        bool aileronStatus;
        bool rudderStatus;
        bool throttleStatus;

	// Make this one at end of class
	char serialDataIn[]; // Data read form serial {unknown if necessary}
    };
}

#endif
