#include "car.h"

Car::Car()
{

}

void Car::move()
{
    position += speed * direction;
    emit positionChanged(position);
}

void Car::positionChanged(int newPosition)
{

}
