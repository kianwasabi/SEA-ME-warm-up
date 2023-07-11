#ifndef CAR
#define CAR 

#include <iostream>
#include <string>

using namespace std; 

class Car{
    private:
        string name_; 
        int speed_;
    public:
        // Default Constructor
        Car();
        
        // Parameterized Constructor
        Car(const string& carName, int carSpeed);

        // Copy Constructor (Shallow)
        explicit Car(const Car& other);

        // Assignment Operator Overload
        Car& operator = (const Car& car);

        // Deconstructor
        ~Car();

        // Getter Functions
        string getname() const;
        int getspeed() const;
};
#endif