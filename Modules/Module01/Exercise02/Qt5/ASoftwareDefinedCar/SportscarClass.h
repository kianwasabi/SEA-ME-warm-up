#pragma once

#include "CarClass.h"

#ifndef SPORTSCARCLASS_H
#define SPORTSCARCLASS_H

class SportsCar: public Car{
private:
    shared_ptr<short> topspeed_;
public:
    // Default Constructor
    SportsCar();
    // Parameterierzed Constructor
    SportsCar(const string& make, short year, const string& model, short topspeed);
    // Deep Copy Constructor
    SportsCar(const SportsCar& other);
    // Assigment Operatort Overload
    SportsCar& operator=(const SportsCar& other);
    // Destructor
    ~SportsCar();
    // Getter & Setter Functions
    short gettopspeed() const;
    void settopspeed(int topspeed);
    // Functions
    void drive();
    // Pure Virtual Function (Run-time polymorphism (Method overriding))
    void honk() const override;
    // For further explanation, see .cpp file
};

#endif // SPORTSCARCLASS_H
