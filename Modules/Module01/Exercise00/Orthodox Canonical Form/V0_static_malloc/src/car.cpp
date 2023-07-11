#include "../include/car.h"

// Default Constructor
Car::Car(){}

// Parameterized Constructor
Car::Car(const string& carName, int carSpeed){
    name_ = carName; 
    speed_ = carSpeed; 
    cout << "Constructor called." << name_ << "," << speed_ << endl;
}

// Copy Constructor
// Shallow Copy
Car::Car(const Car& other){
    name_ = other.name_; 
    speed_ = other.speed_;
    //name = string(other.name); // Deep Copy?
    cout << "Copy Constructor called." << name_ << "," << speed_ << endl;
}

// Assignment Operator Overload
// Use if you want to copy data of an existing object into another exisiting object. 
Car& Car::operator = (const Car& car){
    if(this!=&car)
    {   
        name_ = car.name_;      //shallow copy
        speed_ = car.speed_;    //shallow copy
    }
    cout << "Assignment Operator Overload called." << endl;
    return *this;
}

// Deconstructor
Car::~Car(){ 
    cout << "Destructor called." << name_ << endl;
}

// Getter functions
string Car::getname() const {
    return name_;
}
int Car::getspeed() const {
    return speed_;
}
