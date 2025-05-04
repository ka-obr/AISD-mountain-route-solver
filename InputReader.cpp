#include "InputReader.h"


int InputReader::readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

void InputReader::readStart(int* W, int* H, Point* start, Point* end, int* L) {
    *W = readInt();
    *H = readInt();
    start->x = readInt();
    start->y = readInt();
    end->x = readInt();
    end->y = readInt();
    *L = readInt();
}


void InputReader::readGrid(int* grid, int W, int H) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            grid[i * W + j] = readInt();
        }
    }
}

void InputReader::readLifts(Lift* lifts, int L) {
    for (int i = 0; i < L; i++) {
        lifts[i].start.x = readInt();
        lifts[i].start.y = readInt();
        lifts[i].end.x = readInt();
        lifts[i].end.y = readInt();
        lifts[i].travelTime = readInt();
        lifts[i].departureTime = readInt();
    }
}