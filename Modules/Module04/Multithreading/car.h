#pragma once

#ifndef CAR_H
#define CAR_H


class Car
{
public:
    int position;
    int speed;
    int direction;
    Car();
    void move()
    {
        position += speed * direction;
        emit positionChanged(position);
    }
signals:
    void positionChanged(int newPosition);
};

#endif // CAR_H
