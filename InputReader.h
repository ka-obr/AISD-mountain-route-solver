#ifndef INPUT_READER_H
#define INPUT_READER_H

#include <cstdio>

using namespace std;

struct Point {
    int x;
    int y;
};

class InputReader {
public:
    int nextInt() {
        int x;
        scanf("%d", &x);
        return x;
    }

    void readStart(int* W, int* H, Point* start, Point* end, int* L) {
        *W = nextInt();
        *H = nextInt();
        start->x = nextInt();
        start->y = nextInt();
        end->x = nextInt();
        end->y = nextInt();
        *L = nextInt();      

    }
    void readGrid(int* grid, int W, int H) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                grid[i * W + j] = nextInt();
            }
        }
    }
};

#endif