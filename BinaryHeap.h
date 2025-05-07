#pragma once

#include "Point.h"

struct HeapNode {
    Point index;
    int cost;
};

class BinaryHeap {
    HeapNode* heapArray;
    int heapSize;
    int maxSize;
public:
    explicit BinaryHeap(int maxSize);
    ~BinaryHeap();
    void push(Point index, int cost);
    HeapNode pop();
    bool empty() const;
};