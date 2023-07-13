#pragma once

#include "engineclass.h"
#include "brakeclass.h"
#include "transmissionclass.h"
#include "wheelclass.h"

#ifndef CARCLASS_H
#define CARCLASS_H

class Car {
private:
    Engine* engine_;
    Wheel* wheel_;
    Brake* brake_;
    Transmission* transmission_;
    int numBrakes_ = 4;
    int numWheels_ = 4;

public:
    // Default Constructor (no parameterized Constructor provided)
    Car();
    // Deconstructor
    ~Car();
    // setter & getter functions
    void setEngine(const Engine& engine);
    void setWheel(const Wheel& engine, int numWheels);
    void setBrake(const Brake& brake, int numBrakes);
    void setTransmission(const Transmission& engine);
    // functions
    void printParts();
    // more detailed informations can be found in the .cpp
};

#endif // CARCLASS_H
