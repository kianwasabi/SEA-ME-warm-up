#pragma once

#ifndef RACETRACK_H
#define RACETRACK_H

class RaceTrack
{
public:
    int size;
    int finishLine;
    RaceTrack();
    void setFinishLine(int newFinishLine) {
        finishLine = newFinishLine;
    }
};
#endif // RACETRACK_H
