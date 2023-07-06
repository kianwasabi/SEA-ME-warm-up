- Implement Car class
    - Member variable
        - name
        - speed
    - Member function
        - Constructor
        - Copy constructor
        - Copy assignment operator override
        - Destructor
- Make an example with main function

#include <iostream>
#include <string>

class Car{
    private:
        string name; 
        int speed;
    public:
        Car::Car():name(const &string name),speed(const &int speed){}
}

int main(){
    return 0;
}