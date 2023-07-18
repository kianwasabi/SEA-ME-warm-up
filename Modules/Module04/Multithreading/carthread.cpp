#include "carthread.h"

CarThread::CarThread(Car *car) : car(car)
{

}

void CarThread::run()
{
    while (car->position < raceTrack->finishLine)
    {
        car->move();
        /*Synchronizing the threads:*/
        mutex.lock(); // Acquire a lock before moving the car
        car->move();
        mutex.unlock(); // Release the lock after moving the car

        msleep(10); // Wait 10 milliseconds before moving again
    }
}
