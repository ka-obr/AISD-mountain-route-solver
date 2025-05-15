#include <iostream>
#include "InputReader.h"
#include "Point.h"
#include "Lift.h"
#include "BinaryHeap.h"
#include "IndexFormula.h"

#define INFINITY_COST 2147483647 //maximum integer

using namespace std;

void initializeStart(int* distance, bool* visited, BinaryHeap& heap, Point start, int W, int H) {
    for (int i = 0; i < W * H; i++) {
        distance[i] = INFINITY_COST;
        visited[i] = false;
    }

    heap.push(start, 0);
    distance[start.y * W + start.x] = 0;
}

void updateCost(int newCost, int newIndex, int* distance, BinaryHeap& heap, Point newPoint) {
    if (newCost < distance[newIndex]) {
        distance[newIndex] = newCost;
        heap.push(newPoint, newCost);
    }
}

void checkNeighbors(HeapNode root, int* grid, int* distance, BinaryHeap& heap, int W, int H) {
    // up   right   down    left
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    Point cords = root.index;
    int index = indexFormula(cords.x, cords.y, W);

    for(int i = 0; i < 4; i++) {
        int neighborX = cords.x + dx[i];
        int neighborY = cords.y + dy[i];
        if(neighborX >= 0 && neighborX < W && neighborY >= 0 && neighborY < H) {
            int neighborIndex = indexFormula(neighborX, neighborY, W);
            int cost = grid[neighborIndex] > grid[index] ? grid[neighborIndex] - grid[index] + 1 : 1;
            int neighborCost = root.cost + cost;
            updateCost(neighborCost, neighborIndex, distance, heap, {neighborX, neighborY});
        }
    }
}

void checkLifts(Lift** liftsMap, HeapNode root, BinaryHeap& heap, int* distance, int W) {
    Point cords = root.index;
    int liftIndex = indexFormula(cords.x, cords.y, W);

    if(liftsMap[liftIndex] != nullptr) {
        Lift* currentLift = liftsMap[liftIndex];
        while(currentLift != nullptr) {
            int liftEndIndex = indexFormula(currentLift->end.x, currentLift->end.y, W);

            //checking our actual time is multiple of time for starting lift
            int wait = root.cost % currentLift->departureTime == 0 ? 0 : currentLift->departureTime - (root.cost % currentLift->departureTime);
            int cost = wait + currentLift->travelTime;
            int liftCost = root.cost + cost;
            updateCost(liftCost, liftEndIndex, distance, heap, currentLift->end);
            currentLift = currentLift->nextLift;
        }
    }
}

int findShortestPath(int* grid, int W, int H, Point start, Point end, Lift** liftsMap, int L)
{
    BinaryHeap heap(W * H);
    int* distance = new int[W * H];
    bool* visited = new bool[W * H];

    initializeStart(distance, visited, heap, start, W, H);

    while(!heap.empty()) {
        HeapNode root = heap.pop();
        Point cords = root.index;
        int index;

        //checking have we reached the final point
        if(cords == end) {
            delete[] distance;
            delete[] visited;
            return root.cost;
        }

        index = indexFormula(cords.x, cords.y, W);

        if(visited[index])
            continue;

        visited[index] = true;

        checkNeighbors(root, grid, distance, heap, W, H);
        if(L > 0) 
            checkLifts(liftsMap, root, heap, distance, W);
    }

    delete[] distance;
    delete[] visited;
    return 0;
}

void initializeInput(int* W, int* H, Point* start, Point* end, int* L, Lift**& liftsMap, int*& grid) {
    InputReader input;

    input.readStart(W, H, start, end, L);

    if (*L > 0) {
        liftsMap = new Lift*[(*W) * (*H)];
        input.readLifts(liftsMap, *L, *W, *H);
    }

    grid = new int[(*W) * (*H)];
    input.readGrid(grid, *W, *H);
}

int main()
{
    Point start;
    Point end;
    Lift** liftsMap = nullptr;
    int* grid = nullptr;
    int W, H, L;

    initializeInput(&W, &H, &start, &end, &L, liftsMap, grid);

    cout << findShortestPath(grid, W, H, start, end, liftsMap, L);

    delete[] grid;
    if (liftsMap)
        delete[] liftsMap;
}
