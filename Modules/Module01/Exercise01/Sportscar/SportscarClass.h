#include "CarClass.h"

#ifndef SPORTSCARCLASS_H
#define SPORTSCARCLASS_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class SportsCar: public Car{
private:
    shared_ptr<short> topspeed_;
public:
    // Default Constructor
    SportsCar();

    // Parameterized Constructor
    SportsCar(const string& make, short year, const string& model, short topspeed);

    // Deep Copy Constructor
    SportsCar(const SportsCar& other);

    // Assignment Operator Overload
    SportsCar& operator=(const SportsCar& other);

    // Destructor
    ~SportsCar();

    // Function
    void drive();
};

#endif // SPORTSCARCLASS_H
