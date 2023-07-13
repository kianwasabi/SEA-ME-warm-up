#pragma once

#include "partclass.h"

#ifndef ENGINECLASS_H
#define ENGINECLASS_H

class Engine : public Part {
protected:
    shared_ptr<short>  power_;
    shared_ptr<string> typ_;
    shared_ptr<string> fuel_;
public:
    //Default Constructor
    Engine();
    //Parameterized Constructor
    Engine(short serialnumber, short power, const string& typ, const string& fuel);
    //Deep Copy Constructor
    Engine(Engine& other);
    //Assigment Operator Override
    //Engine& operator=(const Engine& other);
    //Setter & Getter
    void setpower(short power);
    void settyp(const string& typ);
    void setfuel(const string& fuel);
    short getpower() const;
    string gettyp() const;
    string getfuel() const;
    //pure virtual function override
    void print() override;
};

#endif // ENGINECLASS_H
