#pragma once

#ifndef PARTCLASS_H
#define PARTCLASS_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Part {
protected:
    shared_ptr<short> serialnumber_;
public:
    // Defalut Constructor
    Part();
    //parametrized Constructor
    Part(short serialnumber);
    // setter & getter
    void setserialnumber(short serialnumber);
    short getserialnumber() const;
    // Pure virtual function to be overridden by derived classes
    virtual void print() = 0;
};

#endif // PARTCLASS_H
