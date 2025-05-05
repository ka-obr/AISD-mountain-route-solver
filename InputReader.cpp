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

void InputReader::readLifts(Lift* lifts, int L) {
    for (int i = 0; i < L; i++) {
        lifts[i].start.x = read();
        lifts[i].start.y = read();
        lifts[i].end.x = read();
        lifts[i].end.y = read();
        lifts[i].travelTime = read();
        lifts[i].departureTime = read();
    }
}