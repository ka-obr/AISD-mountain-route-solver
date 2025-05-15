#pragma once

#include "Point.h"
#include "Lift.h"

#include <stdio.h>

using namespace std;

class InputReader {
public:
    static int read();
    static void readStart(int* W, int* H, Point* start, Point* end, int* L);
    static void readGrid(int* grid, int W, int H);
    static void readLifts(Lift** liftsMap, int L, int W, int H);
};