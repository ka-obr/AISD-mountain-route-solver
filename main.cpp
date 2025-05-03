#include <iostream>
#include "InputReader.h"

using namespace std;

int main(int argc, char const *argv[])
{
    InputReader input;
    Point start;
    Point end;
    int W, H, L;
    input.readStart(&W, &H, &start, &end, &L);

    int* grid = new int[W * H];
    input.readGrid(grid, W, H);

    cout << "Grid[2]" << grid[2] << endl;

    delete[] grid;
    return 0;
}
