#ifndef __CARCLASS__
#define __CARCLASS__

#include <iostream>
#include <string>

using namespace std; 

class Car{
    private:
        string* make_; 
        short* year_;
        string* model_;
    public:
        // Default Constructor
        Car();
        // Parameterized Constructor
        Car(const string& model, short year, const string& make);
        // Copy Constructor (Shallow)
        explicit Car(const Car& other);
        // Assignment Operator Overload
        Car& operator = (const Car& car);
        // Deconstructor
        ~Car();
        // Getter Functions
        string getmake() const;
        short getyear() const;
        string getmodel() const;
        string getmemoryofobjatt() const; 
        // Functions 
        void pmocc() const;
        void drive();
};
#endif