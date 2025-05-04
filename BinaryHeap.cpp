#include "Point.h"
#include "BinaryHeap.h"
#include <utility>
#include <stdexcept>

BinaryHeap::BinaryHeap(int maxSize) {
    heapArray = new HeapNode[maxSize];
    heapSize = 0;
}

BinaryHeap::~BinaryHeap() {
    delete[] heapArray;
}

bool BinaryHeap::empty() {
    return heapSize == 0;
}

void BinaryHeap::push(Point index, int cost) {
    heapSize++;
    heapArray[heapSize - 1] = {index, cost};
    int i = heapSize - 1;
    while( i > 0 && heapArray[(i - 1)/2].cost > heapArray[i].cost) {
        std::swap(heapArray[(i - 1)/2], heapArray[i]);
        i = (i - 1)/2;
    } 
}

HeapNode BinaryHeap::pop() {
    if(heapSize != 0) {
        HeapNode root = heapArray[0];
        heapSize--;
        heapArray[0] = heapArray[heapSize];
        int i = 0;
        while(2 * i + 1 < heapSize) {
            int child = 2 * i + 1;
            if(child + 1 < heapSize && heapArray[child].cost > heapArray[child + 1].cost)
                child++;
            if(heapArray[i].cost <= heapArray[child].cost)
                break;
            std::swap(heapArray[i], heapArray[child]);
            i = child;     
        }
        return root;
    }
    throw std::runtime_error("Heap is empty!");
}