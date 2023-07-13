#pragma one

#include "partclass.h"

#ifndef WHEELCLASS_H
#define WHEELCLASS_H

class Wheel : public Part {
protected:
    shared_ptr<double> outsidediameter_;
public:
    //Default Constructor
    Wheel();
    //Parameterized Constructor
    Wheel(short serialnumber, double outsidediameter);
    /*
    //Deep Copy Constructor
    Wheel(Wheel& other);
    //Assigment Operator Override
    Wheel& operator=(const Wheel& other);
    */
    //getter & setter functions
    void setoutsidediamter(double outsidediameter);
    double getoutsidediameter() const;
    //pure virtual function override
    void print() override;
};
#endif // WHEEL_H
