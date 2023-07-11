#pragma once

#include "CarClass.h"

#ifndef TRUCKCARCLASS_H
#define TRUCKCARCLASS_H

class TruckCar:public Car{
private:
    shared_ptr<float> bedwidth_;
    shared_ptr<float> bedlength_;
public:
    //
    TruckCar();
    //
    TruckCar(const string& make, short year, const string& model, float bedlength, float bedwidth);
    //
    TruckCar(const TruckCar& other);
    //
    TruckCar& operator=(const TruckCar& other);
    //
    ~TruckCar();
    // getter & setter function
    float getbedwidth() const;
    float getbedlength() const;
    void setbedwidth(float bedwidth);
    void getbedlength(float bedlength);
    // Function
    void drive();
    // Implementation of the pure virtual function (Run-time polymorphism (Method overriding)
    void honk() const override;
    // For further explanation, see .cpp file
};

#endif // TRUCKCARCLASS_H
