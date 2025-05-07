#include "InputReader.h"

int InputReader::read() {
    int x;
    scanf("%d", &x);
    return x;
}

void InputReader::readStart(int* W, int* H, Point* start, Point* end, int* L) {
    *W = read();
    *H = read();
    start->x = read();
    start->y = read();
    end->x = read();
    end->y = read();
    *L = read();
}


void InputReader::readGrid(int* grid, int W, int H) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            grid[i * W + j] = read();
        }
    }
}

void InputReader::readLifts(Lift** liftsMap, int L, int W, int H) {
    for (int i = 0; i < W * H; i++) {
        liftsMap[i] = nullptr;
    }
    Lift* storeLifts = new Lift[L];
    for (int i = 0; i < L; i++) {
        storeLifts[i].start.x = read();
        storeLifts[i].start.y = read();
        storeLifts[i].end.x = read();
        storeLifts[i].end.y = read();
        storeLifts[i].travelTime = read();
        storeLifts[i].departureTime = read();
        storeLifts[i].nextLift = nullptr;

        int liftIndex = storeLifts[i].start.y * W +  storeLifts[i].start.x;

        if(liftsMap[liftIndex] == nullptr) {
            liftsMap[liftIndex] = &storeLifts[i];
        }
        else {
            Lift* previousLift = liftsMap[liftIndex];
            storeLifts[i].nextLift = previousLift;
            liftsMap[liftIndex] = &storeLifts[i];
        }
    }
}