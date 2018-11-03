//
// Created by wei on 11/3/18.
//

#include "MinHeap.h"
#include <stdio.h>

MinHeap initMinHeap(int capacity) {

    MinHeap minHeap = MALLOC(struct MinHeap, 1);
    minHeap->array = initArray(10);

    return minHeap;

}

int size_MinHeap(MinHeap minHeap) {
    return size_Arr(minHeap->array);
}

bool isEmpty_MinHeap(MinHeap minHeap) {
    return size_Arr(minHeap->array) == 0;
}

static int parent(int index) {
    return (index - 1) >> 1;
}


static int leftChild(int index) {
    return (index << 1) + 1;
}

static int rightChild(int index) {
    return (index << 1) + 2;
}


static int compare_MinHeap(VALUETYPE val1, VALUETYPE val2) {
    return val1 - val2;
}


static void shiftUp_MinHeap(MinHeap minHeap, int index) {

    while (index > 0 &&
           compare_MinHeap(getEle_Array(minHeap->array, index), getEle_Array(minHeap->array, parent(index))) < 0) {

        swap_array(minHeap->array, index, parent(index));
        index = parent(index);

    }

}

void add_MinHeap(MinHeap minHeap, VALUETYPE val) {

    addLast_Array(minHeap->array, val);
    shiftUp_MinHeap(minHeap, size_MinHeap(minHeap) - 1);

}

VALUETYPE extractMin_MinHeap(MinHeap minHeap) {

    VALUETYPE res = getEle_Array(minHeap->array, 0);
    swap_array(minHeap->array, 0, size_MinHeap(minHeap) - 1);
    removeLast_Array(minHeap->array);
    shiftDown_MinHeap(minHeap, 0);

    return res;
}


static void shiftDown_MinHeap(MinHeap minHeap, int index) {

    int size = size_MinHeap(minHeap);
    int i = -1;

    while (leftChild(index) < size) {

        i = leftChild(index);
        if (i + 1 < size && compare_MinHeap(getEle_Array(minHeap->array, i), getEle_Array(minHeap->array, i + 1)) > 0) {
            i = i + 1;
        }

        if (compare_MinHeap(getEle_Array(minHeap->array, i), getEle_Array(minHeap->array, index)) >= 0) {
            return;
        }
        swap_array(minHeap->array, i, index);
        index = i;
    }
}

MinHeap heapify_MinHeap(VALUETYPE *array, int length) {

    MinHeap minHeap = initMinHeap(length);

    for (int i = 0; i < length; ++i) {
        minHeap->array->data[i] = array[i];
        minHeap->array->size = i + 1;
    }
    array = NULL;

    int start = parent(size_MinHeap(minHeap) - 1);
    for (int j = start; j >= 0; --j) {
        shiftDown_MinHeap(minHeap, start);
    }

    return minHeap;
}

