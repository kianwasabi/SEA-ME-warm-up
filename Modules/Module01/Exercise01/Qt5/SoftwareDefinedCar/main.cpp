#include "SportscarClass.h"


int main(int argc, char *argv[])
{

    cout << "--START--" << endl;
    cout << "Init Car 1:" << endl;
    Car car1("E91",2007,"BMW");
    cout << "car1:" << endl;
    cout << &car1 << endl;
    car1.pmocc();
    car1.drive();
    cout << "Init Car 2:" << endl;
    Car car2("Golf",2018,"VW");
    cout << "car2:" << endl;
    cout << &car2 << endl;
    car2.pmocc();
    cout << "Init Car 3: Car car3(car1)" << endl;
    Car car3(car1);
    cout << "car1:" << endl;
    cout << &car1 << endl;
    car1.pmocc();
    cout << "car3:" << endl;
    cout << &car3 << endl;
    car3.pmocc();
    car3.drive();
    cout << "Assigning Car2 to Car1: car1=car2" << endl;
    car1 = car2;
    cout << "car1:" << endl;
    cout << &car1 << endl;
    car1.pmocc();
    car1.drive();
    cout << "car2:" << endl;
    cout << &car2 << endl;
    car2.pmocc();
    car2.drive();
    cout << "Create SportsCar1" << endl;
    SportsCar sportscar1("Bugatti",2005,"Veyron",420);
    cout << "SportsCar1:" << endl;
    sportscar1.drive();
    cout << "--START--" << endl;
    return 0;
}



