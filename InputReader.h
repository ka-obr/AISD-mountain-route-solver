#pragma once
#include "Point.h"
#include "Lift.h"

#include <cstdio>

using namespace std;

class InputReader {
public:
    int readInt();
    void readStart(int* W, int* H, Point* start, Point* end, int* L);
    void readGrid(int* grid, int W, int H);
    void readLifts(Lift* lifts, int L);
};