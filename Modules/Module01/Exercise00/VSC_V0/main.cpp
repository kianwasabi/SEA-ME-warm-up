#include "include/car.h"
int main(){
    // Initialize car0 - Default Constructor
    Car car0;
    // Initialize car1 and car2 - Parameterized Constructor
    Car car1("BMW", 100);   
    Car car2("VW", 120); 
    // Copying data of car 2 in car 1 - Assigning Operator
    car1 = car2; 
    // Copy Constructor
    Car copy_car1(car1);
    return 0; //ran without errors
}