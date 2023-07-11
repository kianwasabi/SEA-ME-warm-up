#include "SportscarClass.h"

//Default Constructor
SportsCar::SportsCar(): topspeed_(make_shared<short>(0)) {
    cout << "#SportsCar Default Constructor called." << endl;
}

// Parameterized Constructor
SportsCar::SportsCar(const string& make, short year, const string& model, short topspeed)
    : Car(make, year, model), topspeed_(make_shared<short>(topspeed)) {
    cout << "#SportsCar Parameterized Constructor called." << endl;
}

// Deep Copy Constructor
SportsCar::SportsCar(const SportsCar& other)
    : Car(other), topspeed_(make_shared<short>(*other.topspeed_)) {
    cout << "#SportsCar Deep Copy Constructor called." << endl;
    cout << "#Data of " << &(other) << " deep copyied to " << &(*this)  << "." << endl;
}

// Assignment Operator Overload
SportsCar& SportsCar::operator=(const SportsCar& other) {
    if (this != &other) {
        Car::operator=(other);
        topspeed_ = other.topspeed_;
    }
    cout << "#SportsCar Assignment Operator Overload called." << endl;
    return *this;
}

// Destructor
SportsCar::~SportsCar() {
    cout << "#SportsCar Destructor called for " << &(*this) << endl;
}

// Getter & Setter Functions
/*Encuplation -
Internal state of the object is not directly accessible from outside the class.*/
short SportsCar::gettopspeed() const{
    return *topspeed_;
}
void SportsCar::settopspeed(int topspeed){
    *topspeed_ = topspeed;
}

//Functions
/* Polymorphism - Calls & Extent function of base class Car.*/
void SportsCar::drive() {
    Car::drive();
    cout << "Topspeed: " << *topspeed_ << endl;
}

// Pure Virtual Function
/*Run-time polymorphism (Method overriding) -
Implimentation for a PVF in the base class.
This interface will be overriden for this subclass.*/
void SportsCar::honk() const{
    cout << "Sportscar is honking!" << endl;
}
