#include "CarClass.h"

// Default Constructor
/*Assigns default values if object is initialized without parameters. */
Car::Car() : make_(std::make_shared<std::string>("Not provided.")),
    year_(std::make_shared<short>(0000)),
    model_(std::make_shared<std::string>("Not provided."))
{
    cout << "#Car Default Constructor called." << endl;
}

// Parameterized Constructor
Car::Car(const string& make, short year, const string& model)
    : make_(make_shared<string>(make)),
    year_(make_shared<short>(year)),
    model_(make_shared<string>(model))
{
    cout << "#Car Parameterized Constructor called." << endl;
}

// Deep Copy Constructor
/*Called when the new object is not yet initialized.
 Dereferences the values of the parent object and stores them in the variable of the new object.*/
Car::Car(const Car& other)
    : make_(make_shared<string>(*other.make_)),
    year_(make_shared<short>(*other.year_)),
    model_(make_shared<string>(*other.model_))
{
    cout << "#Car Deep Copy Constructor called." << endl;
    cout << "#Data of " << &(other) << " deep copyied to " << &(*this)  << "." << endl;
}

// Assignment Operator Overload
/*Shallow copy data of an existing object into another exisiting object.
Parent and Child Object refere to data with the same reference.
Constructor is called in run-time, hence */
Car& Car::operator = (const Car& other){
    if(this!=&other)
    {
        make_ = other.make_;
        year_ = other.year_;
        model_ = other.model_;
    }
    cout << "#Car Assignment Operator Overload called." << endl;
    cout << "#Data of " << &(other) << " shallow copyied to " << &(*this) << "." << endl;
    return *this;
}

// Deconstructor
/*Smart&shared pointers automatically manage the memory allocation and deallocation of dynamically allocated objects.
Hence, the default deconstructor can be used.*/
Car::~Car(){
    cout << "#Car Destructor called for " << &(*this) << endl;
}

// Getter & Setter Functions
/*Encuplation -
Internal state of the object is not directly accessible from outside the class.*/
string Car::getmake() const {
    return *make_;
}
short Car::getyear() const {
    return *year_;
}
string Car::getmodel() const {
    return *model_;
}
void Car::setmake(const string& make){
    *make_ = make;
}
void Car::setyear(short year){
    *year_ = year;
}
void Car::setmodel(const string& model){
    *model_ = model;
}

// Functions
void Car::drive(){
        cout << "Your are driving a car with these specs: " << endl;
        cout << "Make:" << getmake() << endl;
        cout << "Year:" << getyear() << endl;
        cout << "Model:" << getmodel() << endl;
}

// Pure Virtual Function
/*Run-time polymorphism (Method overriding) -
There is not Implimentation for a PVF in the base class.
This interface will be overriden in the subclass.*/
