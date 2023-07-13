#include "transmissionclass.h"

Transmission::Transmission():gears_(make_shared<short>(0)),
                             automatik_(make_shared<bool>(!true)){}

Transmission::Transmission(short serialnumber, short gears, bool automatik):Part(serialnumber),
                                                        gears_(make_shared<short>(gears)),
                                                        automatik_(make_shared<bool>(automatik)){}

//Transmission::Transmission(Transmission& other){}

void Transmission::setgears(short gears){
    *gears_ = gears;
}

void Transmission::setautomatik(bool automatik){
    *automatik_ = automatik;
}

short Transmission::getgears() const{
    return *gears_;
}

bool Transmission::getautomatik() const{
    return *automatik_;
}

void Transmission::print(){
    cout << "   Part: Transmission"<<endl;
    cout << "   #: "     << *serialnumber_  <<endl;
    cout << "   gears: " << *gears_ << endl;
    cout << "   automatik: "   << *automatik_ << endl;
}
