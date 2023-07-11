#include "CarClass.h"
#include "SportscarClass.h"
#include "TruckCarClass.h"

int main(int argc, char *argv[])
{
    cout << "-----START-----" << endl;
    cout << "1) Class SportsCar" << endl;
    cout << "### Create Buggati#0 Sportscar: " << endl;
    cout << "##$ Buggati0 (Bugatti 2005 Veyron 420)" << endl;
    SportsCar Buggati0("Bugatti",2005,"Veyron",420);
    Buggati0.drive();
    Buggati0.honk();
    cout << "### Create Buggati#1 with equal specs using the Deep Copy Constructor" << endl;
    cout << "##$ SportsCar Buggati1(Buggati0)" << endl;
    SportsCar Buggati1(Buggati0);
    Buggati1.drive();
    cout << "### Change Year and Topspeed of Buggati#0: " << endl;
    cout << "##$ Buggati0.setyear(2006)" << endl;
    Buggati0.setyear(2006);
    cout << "##$ Buggati0.settopspeed(380)" << endl;
    Buggati0.settopspeed(380);
    Buggati0.drive();
    cout << "### Crached the Buggati#0! Shell is damaged, but powertrain and electronics are fine." << endl;
    cout << "### Create an empty Buggati#2." << endl;
    cout << "##$ SportsCar Buggati2" << endl;
    SportsCar Buggati2;
    Buggati2.drive();
    cout << "### Put Buggati#0's components in Buggati#2 using the Assigment Operator Override." << endl;
    cout << "##$ Buggati2 = Buggati0" << endl;
    Buggati2 = Buggati0;
    cout << "##! Buggati#0 and Buggati#2 are sharing the same components now." << endl;
    Buggati0.drive();
    Buggati2.drive();
    cout << "### Change Topspeed of Buggati#2:" << endl;
    cout << "##$ Buggati2.settopspeed(220)" << endl;
    Buggati2.settopspeed(220);
    cout << "### Compare Buggati#0 & Buggati#2:" << endl;
    Buggati2.drive();
    Buggati0.drive();
    cout << "### Change Topspeed of Buggati#0:" << endl;
    cout << "##$ Buggati0.settopspeed(100)" << endl;
    Buggati0.settopspeed(100);
    cout << "### Compare Buggati#0 & Buggati#2:" << endl;
    Buggati2.drive();
    Buggati0.drive();
    /*cout << "2) Class TruckCar" << endl;
     * cout << "### Create Truck#0" << endl;
     * TruckCar Raptor("Ford",2020,"Raptor",5.1,6.1);
     * Raptor.drive();
     * Raptor.honk();
     * //Similar to SuperCar.*/
    cout << "-----END-----" << endl;
    return 0;
}



