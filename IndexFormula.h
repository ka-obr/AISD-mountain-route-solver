#pragma once

//Formula to get in 1D array point (x,y)     index = y * W + x

inline int index_formula(int x, int y, int W) {
    return y * W + x;
}