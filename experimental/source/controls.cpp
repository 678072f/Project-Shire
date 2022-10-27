// Controls Class v1.0
// Daniel Duhon, 10/20/2022
// Controls Class

// Included files
#include "controls.h"

// Serial Ports
#define PORT1 "/dev/ttyAMA0"
#define PORT2 "/dev/ttyAMA1"
#define PORT3 "/dev/ttyAMA2"

// Controls self-test
Controls::Controls() {
    deflection = "deflection:0";
    // TODO: Need to add function to test comtrols in order to return a value.
    Shire::Serial init1(PORT1);
    Shire::Serial init2(PORT2);
    Shire::Serial init1(PORT3);
    
    init1.writeSerial(deflection);
    init2.writeSerial(deflection);
    init3.writeSerial(deflection);
    
    isActive = init1.readSerial();
    if (!isActive)
        std::printf("Error %i from controls!", errno, strerror(errno));
    
    isActive = init2.readSerial();
    if (!isActive)
        std::printf("Error %i from controls!", errno, strerror(errno));
    
    isActive = init3.readSerial();
    if (!isActive)
        std::printf("Error %i from controls!", errno, strerror(errno));
}

// Read the control input and store it to controlInput
double Controls::readControlInput() {
    // read(control) { return value }
    return 0;
}

// Set the amount of delflection from controlInput to deflection
void Controls::setDeflection(double delta) {
    // command(controlInput) { output = deflectionAmount return output }
}

// Read the deflection variable
double getDeflection() {
    // getDeflectionAmount() { return value }
    return 0;
}

// Clean up program upon shutdown
Controls::~Controls() {
    std::cout << "Bye bye!\n";
    // clean up before shutdown
}
