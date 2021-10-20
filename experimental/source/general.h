#ifndef GENERAL_H
#define GENERAL_H

// Includes, these are what needs to be used in main.cpp.
#include <math.h> // Not used yet...
#include <iostream> // cout, cin, etc.
#include <string> // For C++ Strings
#include "serial.h" // For testing Serial class. May be removed in future versions.

namespace Shire {

// Version and Build variables
static std::string versionNumber = "0.0.1c"; // 0.0.1 = Serial, 0.0.2 = controls, etc.
static std::string buildNumber = "0001c"; // Build Number = 0 + version number + letter corresponding to build (a = first build, b = second build, etc.).

}

#endif
