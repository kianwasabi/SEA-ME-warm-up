#include "SportscarClass.h"

// Default Constructor
SportsCar::SportsCar() : topspeed_(make_shared<short>()) {
    cout << "SportsCar Default Constructor called." << endl;
}

// Parameterized Constructor
SportsCar::SportsCar(const string& make, short year, const string& model, short topspeed)
    : Car(make, year, model), topspeed_(make_shared<short>(topspeed)) {
    cout << "SportsCar Parameterized Constructor called." << endl;
}

// Deep Copy Constructor
SportsCar::SportsCar(const SportsCar& other)
    : Car(other), topspeed_(make_shared<short>(*other.topspeed_)) {
    cout << "SportsCar Deep Copy Constructor called." << endl;
}

// Assignment Operator Overload
SportsCar& SportsCar::operator=(const SportsCar& other) {
    if (this != &other) {
        Car::operator=(other);
        topspeed_ = other.topspeed_;
    }
    cout << "SportsCar Assignment Operator Overload called." << endl;
    return *this;
}

// Destructor
SportsCar::~SportsCar() {
    cout << "SportsCar Destructor called for " << &(*this) << endl;
}

// Function
void SportsCar::drive() {
    Car::drive();
    cout << "Speed: " << *topspeed_ << endl;
}
