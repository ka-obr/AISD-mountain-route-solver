#pragma once

#include "Point.h"
#include "Lift.h"

#include <cstdio>

using namespace std;

class InputReader {
public:
    static int read();
    static void readStart(int* W, int* H, Point* start, Point* end, int* L);
    static void readGrid(int* grid, int W, int H);
    static void readLifts(Lift* lifts, int L);
};