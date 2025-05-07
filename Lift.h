#pragma once

#include "Point.h"

class Lift {
public:
    Point start;
    Point end;
    int travelTime;
    int departureTime;
    Lift* nextLift;
};