#include "../include/CarClass.h"

// Default Constructor
Car::Car() : make_(nullptr), year_(nullptr), model_(nullptr) {}

// Parameterized Constructor
// Gets reference of passed value and saves them in new variable. Then the object variable pointer points to the new variable. 
Car::Car(const string& model, short year, const string& make){
    make_  = new string(make); 
    year_  = new short (year);
    model_ = new string(model);
    cout << "Constructor called." << endl;
}

// Deep Copy Constructor 
// Called if new object is not init yet. Dereferences the parent's values and saves them in new object variable.
Car::Car(const Car& other){
    make_  = new string(*(other.make_)); 
    year_  = new short (*(other.year_));
    model_ = new string(*(other.model_));
    cout << "Copy Constructor called." << endl;
    // delete make_;
    // delete year_;
    // delete model_;
}

// Assignment Operator Overload
// Use if you want to copy data of an existing object into another exisiting object. Creates shallow copy. 
Car& Car::operator = (const Car& other){
    if(this!=&other)
    {   
        // delete make_;
        // delete year_;
        // delete model_;
        make_ = other.make_;
        year_ = other.year_;
        model_ = other.model_;
    }
    cout << "Assignment Operator Overload called." << &(other) << "-data moved->" << &(*this) << endl;
    return *this;
}

// Deconstructor
// Deallocate the dynamic memory (obj var ptr & obj)
Car::~Car(){ 
    delete make_;
    delete year_;
    delete model_;
    cout << "Destructor called:" << &(*this) << endl;
    cout << make_ << "," << year_ << "," << model_ << endl;
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
    cout << "Driving" << "-" << &(*this) << "," << this->make_ << "," << this->model_ << "," << this->year_ << endl;
}
