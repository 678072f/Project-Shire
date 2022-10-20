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
    Controls(); // Contructor
    double readControlInput();
    void setDeflection(double delta); // Set the control deflection
    double getDeflection(); // Output the deflection amount for indicating deflections
    ~Controls(); // Destructor
private:
    double controlInput; // Variable to store the control input
    double deflection; // Variable to store deflection
};

#endif
