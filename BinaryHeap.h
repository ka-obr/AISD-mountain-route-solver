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
    static void swap(HeapNode& node1, HeapNode& node2);
    HeapNode pop();
    bool empty() const;
};