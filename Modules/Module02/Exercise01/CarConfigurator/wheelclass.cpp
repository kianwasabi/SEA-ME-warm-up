#include "wheelclass.h"

Wheel::Wheel():outsidediameter_(make_shared<double>(0.0)){}

Wheel::Wheel(short serialnumber, double outsidediameter):Part(serialnumber),outsidediameter_(make_shared<double>(outsidediameter)){}

//Wheel& Wheel::operator=(const Wheel& other){}

void Wheel::setoutsidediamter(double outsidediameter){
    *outsidediameter_= outsidediameter;
}
double Wheel::getoutsidediameter() const{
    return *outsidediameter_;
}

void Wheel::Wheel::print(){
    cout << "   Part: Wheel"<<endl;
    cout << "   #: "     << *serialnumber_  <<endl;
    cout << "   outsidediameter: " << *outsidediameter_ << endl;
}
