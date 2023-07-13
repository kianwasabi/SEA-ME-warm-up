#include "carclass.h"

int main() {
    cout << "-------" << endl;
    // First, create an empty car shell.
    Car bmwE91;
    // Second, create car parts that you want to put in your car.
    Engine bmwE91Engine(1337,120,"Combustion","Gasoline");
    Transmission bmwE91Transmission(4502,6,true);
    Brake bmwE91Break(4277,2.1);
    Wheel bmwE91Wheel(8922,21);
    // Third, put car parts in your empty car shell.
    bmwE91.setEngine(bmwE91Engine);
    bmwE91.setTransmission(bmwE91Transmission);
    bmwE91.setWheel(bmwE91Wheel,4);
    bmwE91.setBrake(bmwE91Break,4);
    // Look at your car!
    bmwE91.printParts();
    cout << "-------" << endl;
    // Nevermind, customer wants another set of brakes and another engine.
    // First, change part specs.
    bmwE91Break.setserialnumber(0001);
    bmwE91Break.setfrictioncoefficient(1.1);
    bmwE91Engine.setserialnumber(0002);
    bmwE91Engine.settyp("Electric");
    bmwE91Engine.setfuel("Electricity");
    // Second, assign parts to car.
    bmwE91.setBrake(bmwE91Break,4);
    bmwE91.setEngine(bmwE91Engine);
    // Look at your car again!
    bmwE91.printParts();
    cout << "-------" << endl;

    return 0;
}
