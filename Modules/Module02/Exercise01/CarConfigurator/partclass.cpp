#include "partclass.h"

Part::Part():serialnumber_(make_shared<short>(0)){}

Part::Part(short serialnumber):serialnumber_(make_shared<short>(serialnumber)){}

void Part::setserialnumber(short serialnumber){
    *serialnumber_ = serialnumber;
}

short Part::getserialnumber() const{
    return *serialnumber_;
}
