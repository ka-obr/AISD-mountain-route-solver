#include <iostream>
#include <climits>
#include "InputReader.h"
#include "Point.h"
#include "Lift.h"
#include "BinaryHeap.h"

using namespace std;

//Formula to get in 1D array point (x,y) index = y * W + x

int index_formula(int x, int y, int W) {
    return y * W + x;
}

void initialize_start(int* distance, bool* visited, BinaryHeap& heap, Point start, int W, int H) {
    for (int i = 0; i < W * H; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    heap.push(start, 0);
    distance[start.y * W + start.x] = 0;
}

void check_neighbors(HeapNode root, int* grid, int* distance, BinaryHeap& heap, int W, int H) {
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    Point cords = root.index;
    int index = index_formula(cords.x, cords.y, W);

    for(int i = 0; i < 4; i++) {
        int newX = cords.x + dx[i];
        int newY = cords.y + dy[i];
        if(newX >= 0 && newX < W && newY >=0 && newY < H) {
            int newIndex = index_formula(newX, newY, W);
            int cost = grid[newIndex] > grid[index] ? grid[newIndex] - grid[index] + 1 : 1;
            int newCost = root.cost + cost;
            if(newCost < distance[newIndex]) {
                distance[newIndex] = newCost;
                heap.push({newX, newY}, newCost);
            }
        }
    }
}

void check_lifts(Lift* lifts, HeapNode root, BinaryHeap& heap, int* distance, int W, int L) {
    Point cords = root.index;

    for (int i = 0; i < L; i++) {
        if (lifts[i].start == cords) {
            //checking our actual time is multiple of time for starting lift
            int wait = root.cost % lifts[i].departureTime == 0 ? 0 : lifts[i].departureTime - (root.cost % lifts[i].departureTime);

            int cost = wait + lifts[i].travelTime;
            int liftCost = root.cost + cost;
            int liftEndIndex = index_formula(lifts[i].end.x, lifts[i].end.y, W);
            if (liftCost < distance[liftEndIndex]) {
                distance[liftEndIndex] = liftCost;
                heap.push(lifts[i].end, liftCost);
            }
        }
    }
}

int findShortestPath(int* grid, int W, int H, Point start, Point end, Lift* lifts, int L)
{
    BinaryHeap heap(W * H);
    int* distance = new int[W * H];
    bool* visited = new bool[W * H];

    initialize_start(distance, visited, heap, start, W, H);

    while(!heap.empty()) {
        HeapNode root = heap.pop();
        Point cords = root.index;

        //checking have we reached the final point
        if(cords == end) {
            delete[] distance;
            delete[] visited;
            return root.cost;
        }

        int index = index_formula(cords.x, cords.y, W);

        if(visited[index]) {
            continue;
        }

        visited[index] = true;

        check_neighbors(root, grid, distance, heap, W, H);
        check_lifts(lifts, root, heap, distance, W, L);
    }

    delete[] distance;
    delete[] visited;
    return 0;
}

int main()
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

    cout << findShortestPath(grid, W, H, start, end, lifts, L);

    delete[] grid;
    if (lifts) {
        delete[] lifts;
    }
}
