#include <iostream>
#include "InputReader.h"
#include "Point.h"
#include "Lift.h"
#include "BinaryHeap.h"

using namespace std;

int main(int argc, char const *argv[])
{
    InputReader input;
    Point start;
    Point end;
    int W, H, L;
    input.readStart(&W, &H, &start, &end, &L);

    Lift* lifts = nullptr;
    if (L > 0) {
        lifts = new Lift[L];
        input.readLifts(lifts, L);
    }

    int* grid = new int[W * H];
    input.readGrid(grid, W, H);

    delete[] grid;
    if (lifts) {
        delete[] lifts;
    }
}
