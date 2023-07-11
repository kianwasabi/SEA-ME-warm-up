#include "include/CarClass.h"
int main(){
    cout << "--START--" << endl;
    cout << "Creating Car1:" << endl;
    Car car1("E91",2007,"BMW");
    cout << "car1:" << endl; 
    cout << &car1 << endl;
    car1.pmocc(); 
    cout << "car2:" << endl;
    Car car2("Golf",2018,"VW");
    cout << "car2:" << endl; 
    cout << &car2 << endl;
    car2.pmocc(); 
    cout << "Car car3(car1)" << endl;
    Car car3(car1);
    cout << "car1:" << endl; 
    cout << &car1 << endl;
    car1.pmocc();
    cout << car1.getmake() << car1.getyear() << car1.getmodel() << endl;
    cout << "car3:" << endl; 
    cout << &car3 << endl;
    car3.pmocc();
    cout << car3.getmake() << car3.getyear() << car3.getmodel() << endl;
    cout << "car1=car2" << endl;
    car1 = car2;
    cout << "car1:" << endl; 
    cout << &car1 << endl;
    car1.pmocc();
    cout << car1.getmake() << car1.getyear() << car1.getmodel() << endl;
    cout << "car2:" << endl; 
    cout << &car2 << endl;
    car2.pmocc(); 
    cout << car2.getmake() << car2.getyear() << car2.getmodel() << endl;
    cout << "--END--" << endl;
    return 0;
}