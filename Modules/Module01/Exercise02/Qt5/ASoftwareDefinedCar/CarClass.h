#pragma once

#ifndef CARCLASS_H
#define CARCLASS_h

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Car{
protected:
    shared_ptr<string> make_;
    shared_ptr<short> year_;
    shared_ptr<string> model_;
public:
    // Default Constructor
    Car();
    // Parameterized Constructor
    Car(const string& model, short year, const string& make);
    // Deep Copy Constructor
    explicit Car(const Car& other);
    // Assignment Operator Overload
    Car& operator = (const Car& car);
    // Deconstructor
    ~Car();
    // Getter & Setter Functions
    string getmake() const;
    short getyear() const;
    string getmodel() const;
    void setmake(const string& make);
    void setyear(short year);
    void setmodel(const string& model);
    // Function
    void drive();
    // Pure Virtual Function (Run-time polymorphism (Method overriding))
    virtual void honk() const = 0;
    // For further explanation, see .cpp file
};
#endif //CARCLASS_h
