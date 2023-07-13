#pragma once

#include "partclass.h"

#ifndef TRANSMISSIONCLASS_H
#define TRANSMISSIONCLASS_H

class Transmission: public Part{
protected:
    shared_ptr<short> gears_;
    shared_ptr<bool> automatik_;
public:
    //Default Constructor
    Transmission();
    //Parameterized Constructor
    Transmission(short serialnumber, short gears, bool automatik);
    /*
    //Deep Copy Constructor
    Transmission(Transmission& other);
    //Assigment Operator Override
    Transmission& operator=(const Transmission& other);
    */
    //Setter & Getter
    void setgears(short gears);
    void setautomatik(bool automatik);
    short getgears() const;
    bool getautomatik() const;
    //pure virtual function override
    void print() override;
};

#endif // TRANSMISSIONCLASS_H
