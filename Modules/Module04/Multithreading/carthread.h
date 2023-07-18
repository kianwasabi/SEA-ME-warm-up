#pragma once

#ifndef CARTHREAD_H
#define CARTHREAD_H

#include <QThread>

class CarThread : public QThread
{
private:
    Car *car;
    RaceTrack *raceTrack;
public:
    CarThread(Car *car) : car(car) {}
    void run() {
        while (car->position < raceTrack->finishLine) {
            car->move();
            msleep(10); // Wait 10 milliseconds before moving again
        }
    }
};

#endif // CARTHREAD_H
