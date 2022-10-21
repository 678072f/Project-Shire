// Controls Class v1.0
// Daniel Duhon, 10/20/2022
// Controls Class

#ifndef CONTROLS_H
#define CONTROLS_H

// Included libraries
#include <cmath> // For math functions
#include "serial.h" // For serial output

// Define Controls Class
class Controls {
public:
    // Public Variables
    bool isActive;
    
    // Public Functions
    Controls(); // Contructor
    double readControlInput();
    void setDeflection(double delta); // Set the control deflection
    double getDeflection(); // Output the deflection amount for indicating deflections
    ~Controls(); // Destructor
private:
    // Private Variables
    double controlInput; // Variable to store the control input
    char deflection; // Variable to store deflection
    
    // Private Functions
    // TODO: Add private functions if needed
};

#endif
