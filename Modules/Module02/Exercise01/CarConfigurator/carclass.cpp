#include "carclass.h"

// Constructor (no parameterized Constructor is provided, hence the customization needs to be done by setter functions)
Car::Car():engine_(new Engine()),
           wheel_(new Wheel[4]),
           brake_(new Brake[4]),
           transmission_(new Transmission()){}

// Destructor
Car::~Car() {
    delete engine_;
    delete transmission_;
    delete [] wheel_;
    delete [] brake_;
}

// Setter function for the engine
void Car::setEngine(const Engine& engine) {
    engine_->setserialnumber(engine.getserialnumber());
    engine_->setpower(engine.getpower());
    engine_->setfuel(engine.getfuel());
    engine_->settyp(engine.gettyp());
}

// Setter function for the wheels
void Car::setWheel(const Wheel& wheel, int numWheels){
    delete[] wheel_;                //Free previous allocated memory.
    numWheels_ = numWheels;         //Save user's number of wheels.
    wheel_ = new Wheel[numWheels];  // Allocation for new member.
    // Loop through new allocated array and assign same specs for each wheel.
    for (int i = 0; i < numWheels_; ++i) {
        wheel_[i].setserialnumber(wheel.getserialnumber());
        wheel_[i].setoutsidediamter(wheel.getoutsidediameter());
    }
}

// Setter function for the brakes
void Car::setBrake(const Brake& brake, int numBrakes){
    delete[] brake_;
    numBrakes_ = numBrakes;
    brake_ = new Brake[numBrakes];
    for (int i = 0; i < numBrakes_; ++i) {
        brake_[i].setserialnumber(brake.getserialnumber());
        brake_[i].setfrictioncoefficient(brake.getfrictioncoefficient());
    }
}
// Setter function for the transmission
void Car::setTransmission(const Transmission& transmission){
    transmission_->setserialnumber(transmission.getserialnumber());
    transmission_->setgears(transmission.getgears());
    transmission_->setautomatik(transmission.getautomatik());
}

// call prints of parts' subclasses & add some information to it.
void Car::printParts() {
    cout << "Engine:" << endl;
    engine_->print();
    cout << "Transmission" << endl;
    transmission_->print();
    for (int i = 0; i < numWheels_; ++i) {
        cout << "Wheel " << i << endl;
        wheel_[i].print();
        }
    for (int i = 0; i < numBrakes_; ++i) {
        cout << "Brake " << i << endl;
        brake_[i].print();
    }
}
