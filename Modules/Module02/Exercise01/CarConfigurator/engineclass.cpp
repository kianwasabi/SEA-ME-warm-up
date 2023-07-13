#include "engineclass.h"

Engine::Engine():power_(make_shared<short>(0)),
                 typ_(make_shared<string>("typ")),
                 fuel_(make_shared<string>("fuel")){}

Engine::Engine(short serialnumber,short power, const string& typ, const string& fuel):Part(serialnumber),
                                                                                      power_(make_shared<short>(power)),
                                                                                      typ_(make_shared<string>(typ)),
                                                                                      fuel_(make_shared<string>(fuel)){}

//Engine::Engine(Engine& other){}

void Engine::setpower(short power){
    *power_ = power;
}
void Engine::settyp(const string& typ){
    *typ_ = typ;
}
void Engine::setfuel(const string& fuel){
    *fuel_ = fuel;
}

short Engine::getpower() const{
    return *power_;
}
string Engine::gettyp() const{
    return *typ_;
}
string Engine::getfuel() const{
    return *fuel_;
}

void Engine::print(){
    cout << "   Part: Engine"<<endl;
    cout << "   #: "     << *serialnumber_  <<endl;
    cout << "   power: " << *power_  << endl;
    cout << "   typ: "   << *typ_    << endl;
    cout << "   fuel: "  << *fuel_   << endl;
}
