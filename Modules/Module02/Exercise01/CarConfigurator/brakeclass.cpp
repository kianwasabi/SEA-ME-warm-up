#include "brakeclass.h"

Brake::Brake():frictioncoefficient_(make_shared<double>(0.0)){}

Brake::Brake(short serialnumber, double frictioncoefficient):Part(serialnumber),
                                                             frictioncoefficient_(make_shared<double>(frictioncoefficient)){}

void Brake::setfrictioncoefficient(double frictioncoefficient){
    *frictioncoefficient_ = frictioncoefficient;
}

double Brake::getfrictioncoefficient() const{
    return *frictioncoefficient_;
}

void Brake::print(){
    cout << "   Part: Break"<<endl;
    cout << "   #: "     << *serialnumber_  <<endl;
    cout << "   frictioncoefficient: " << *frictioncoefficient_  << endl;
}
