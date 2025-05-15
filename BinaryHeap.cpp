//Inspired by https://www.geeksforgeeks.org/binary-heap/

#include "Point.h"
#include "BinaryHeap.h"
#include <stdexcept>

BinaryHeap::BinaryHeap(int maxSize) : maxSize(maxSize) {
    heapArray = new HeapNode[maxSize];
    heapSize = 0;
}

BinaryHeap::~BinaryHeap() {
    delete[] heapArray;
}

bool BinaryHeap::empty() const {
    return heapSize == 0;
}

void BinaryHeap::swap(HeapNode& node1, HeapNode& node2) {
    HeapNode tempNode = node1;
    node1 = node2;
    node2 = tempNode;
}

int BinaryHeap::leftChild(int i) {
    return 2 * i + 1;
}

int BinaryHeap::rightChild(int i) {
    return 2 * i + 2;
}

int BinaryHeap::parent(int i) {
    return (i - 1)/2;
}

void BinaryHeap::push(Point index, int cost) {
    heapSize++;
    heapArray[heapSize - 1] = {index, cost};
    int i = heapSize - 1;
    while(i > 0 && heapArray[parent(i)].cost > heapArray[i].cost) {
        swap(heapArray[parent(i)], heapArray[i]);
        i = parent(i);
    }
}

HeapNode BinaryHeap::pop() {
    if(heapSize != 0) {
        HeapNode root = heapArray[0];
        heapSize--;
        heapArray[0] = heapArray[heapSize];
        int i = 0;
        while(leftChild(i) < heapSize) {
            int child = leftChild(i);

            //right child is better for lower cost
            if(child + 1 < heapSize && heapArray[child].cost > heapArray[child + 1].cost)
                child++;
            if(heapArray[i].cost <= heapArray[child].cost)
                break;
            swap(heapArray[i], heapArray[child]);
            i = child;
        }
        return root;
    }
    throw std::runtime_error("Heap is empty!");
}