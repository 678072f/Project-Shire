//
//  GPIO.cpp
//  GPIO Class
//
//  Created by Daniel Duhon on 10/21/18.
//

#include <stdio.h>
#include "GPIO.h"
#include <fstream>
#include <string.h>
#include <iostream>
#include<sstream>

GPIOClass::GPIOClass()
{
    this->GPIONum = "0";
}

GPIOClass::GPIOClass(string gnum)
{
    this->GPIONum = gnum;
}

int GPIOClass::exportGPIO()
{
    string export_str = "/sys/class/gpio/export";
    ofstream exportgpio(export_str.c_str());
    
    exportgpio << this->GPIONum;
    exportgpio.close();
    return 0;
}

int GPIOClass::unexportGPIO()
{
    string unexport_str = "/sys/class/gpio/unexport";
    ofstream unexportgpio(unexport_str.c_str());

    unexportgpio << this->GPIONum;
    unexportgpio.close();
    return 0;
}

int GPIOClass::setDirGPIO(string dir)
{
    string setdir_str = "/sys/class/gpio/gpio" + this->GPIONum + "/direction";
    ofstream setdirgpio(setdir_str.c_str());

    setdirgpio << dir;
    setdirgpio.close();
    return 0;
}

int GPIOClass::setValGPIO(string val)
{
    string setval_str = "/sys/class/gpio/gpio" + this->GPIONum + "/value";
    ofstream setvalgpio(setval_str.c_str());

    setvalgpio << val;
    setvalgpio.close();
    return 0;
}

int GPIOClass::getValGPIO(string& val)
{
    string getval_str = "/sys/class/gpio/gpio" + this->GPIONum + "/value";
    ifstream getvalgpio(getval_str.c_str());

    getvalgpio >> val;

    if (val != "0")
        val ="1";
    else
        val = "0";

    getvalgpio.close();
    return 0;
}
