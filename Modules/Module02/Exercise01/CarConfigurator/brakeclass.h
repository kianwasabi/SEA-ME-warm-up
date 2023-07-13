#pragma once

#include "partclass.h"

#ifndef BRAKECLASS_H
#define BRAKECLASS_H

class Brake: public Part{
protected:
    shared_ptr<double> frictioncoefficient_;
public:
    //Default Constructor
    Brake();
    //Parameterized Constructor
    Brake(short serialnumber, double frictioncoefficient);
    /*
    //Deep Copy Constructor
    Brake(Brake& other);
    //Assigment Operator Override
    Brake& operator=(const Brake& other);
    */
    //Setter & Getter functions
    void setfrictioncoefficient(double frictioncoefficient);
    double getfrictioncoefficient() const;
    //pure virtual function override
    void print() override;
};

#endif // BREAKECLASS_H
