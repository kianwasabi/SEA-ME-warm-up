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

    // Copy Constructor (deep)
    explicit Car(const Car& other);

    // Assignment Operator Overload
    Car& operator = (const Car& car);

    // Deconstructor
    ~Car();

    // Getter Functions
    string getmake() const;
    short getyear() const;
    string getmodel() const;

    // Functions
    void pmocc() const;
    void drive();
};
#endif //CARCLASS_h
