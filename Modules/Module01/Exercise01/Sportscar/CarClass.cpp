#include "CarClass.h"

// Default Constructor
Car::Car() //: make_(nullptr), year_(nullptr), model_(nullptr)
//Car::Car() : make_(std::make_shared<std::string>()), year_(std::make_shared<short>()), model_(std::make_shared<std::string>()) //{}
{
    cout << "Default Constructor called." << endl;
}

// Parameterized Constructor
Car::Car(const string& make, short year, const string& model)
    : make_(make_shared<string>(make)),
    year_(make_shared<short>(year)),
    model_(make_shared<string>(model)) {}

// Deep Copy Constructor
// Called if new object is not init yet. Dereferences the parent's values and saves them in new object variable.
Car::Car(const Car& other)
    : make_(make_shared<string>(*other.make_)),
    year_(make_shared<short>(*other.year_)),
    model_(make_shared<string>(*other.model_))
{
    cout << "Deep Copy Constructor called." << endl;
    cout << "Data of " << &(other) << " deep copyied to " << &(*this)  << "." << endl;
}

// Assignment Operator Overload
// Use if you want to copy data of an existing object into another exisiting object. Creates shallow copy.
Car& Car::operator = (const Car& other){
    if(this!=&other)
    {
        make_ = other.make_;
        year_ = other.year_;
        model_ = other.model_;
    }
    cout << "Assignment Operator Overload called." << endl;
    cout << "Data of " << &(other) << " shallow copyied to " << &(*this) << "." << endl;
    return *this;
}

// Deconstructor
Car::~Car(){
    cout << "Destructor called for " << &(*this) << endl;
}

// Getter functions
string Car::getmake() const {
    return *make_;
}

short Car::getyear() const {
    return *year_;
}

string Car::getmodel() const {
    return *model_;
}

void Car::pmocc() const {
        cout << make_ << "," << year_ << "," << model_ << endl;
}

// Functions
void Car::drive(){
        cout << "Driving: " << endl;
        cout << "Make:" << getmake() << endl;
        cout << "Year:" << getyear() << endl;
        cout << "Model:" << getmodel() << endl;
}
