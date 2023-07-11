#include "TruckcarClass.h"

// Default Constructor
TruckCar::TruckCar() :
    bedlength_(make_shared<float>(0.0)),
    bedwidth_(make_shared<float>(0.0)) {
    cout << "#Truck Default Constructor called." << endl;
}

// Parameterized Constructor
TruckCar::TruckCar(const string& make, short year, const string& model, float bedlength, float bedwidth)
    : Car(make, year, model), bedwidth_(make_shared<float>(bedwidth)), bedlength_(make_shared<float>(bedlength)){
    cout << "#Truck Parameterized Constructor called." << endl;
}

// Deep Copy Constructor
TruckCar::TruckCar(const TruckCar& other)
    : Car(other), bedwidth_(make_shared<float>(*other.bedwidth_)), bedlength_(make_shared<float>(*other.bedlength_)) {
    cout << "#Truck Deep Copy Constructor called." << endl;
    cout << "#Data of " << &(other) << " deep copyied to " << &(*this)  << "." << endl;
}

// Assignment Operator Overload
TruckCar& TruckCar::operator=(const TruckCar& other) {
    if (this != &other) {
        Car::operator=(other);
        bedlength_ = other.bedlength_;
        bedwidth_ = other.bedwidth_;
    }
    cout << "#Truck Assignment Operator Overload called." << endl;
    return *this;
}

// Destructor
TruckCar::~TruckCar() {
    cout << "#Truck Destructor called for " << &(*this) << endl;
}

// Getter & Setter Functions
/*Encuplation -
Internal state of the object is not directly accessible from outside the class.*/
float TruckCar::getbedwidth() const{
    return *bedwidth_;
}
float TruckCar::getbedlength() const{
    return *bedlength_;
}
void TruckCar::setbedwidth(float bedwidth){
    *bedwidth_ = bedwidth;
}
void TruckCar::getbedlength(float bedlength){
    *bedlength_ = bedlength;
}

// Functions
/* Polymorphism - Calls & Extent function of base class Car.*/
void TruckCar::drive() {
    Car::drive();
    cout << "Bed size:"<< *bedwidth_ << "x" << *bedlength_ << endl;
}

// Pure Virtual Function
/*Run-time polymorphism (Method overriding) -
Implimentation for a PVF in the base class.
This interface will be overriden for this subclass.*/
void TruckCar::honk() const{
    cout << "Truck is honking!" << endl;
}
