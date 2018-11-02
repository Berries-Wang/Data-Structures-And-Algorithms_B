//
// Created by wei on 9/30/18.
//
#include "MaxHeap.h"
#include <stdio.h>
#include <assert.h>

MaxHeap initMaxHeap(int capacity) {

    MaxHeap maxHeap = MALLOC(struct MaxHeap, 1);
    maxHeap->array = initArray(capacity);

    return maxHeap;

}

MaxHeap initMaxHeap_byArr(VALUETYPE *data, int size) {

    MaxHeap maxHeap = MALLOC(struct MaxHeap, 1);
    maxHeap->array = initArray(size);
    maxHeap->array->size = size;

    for (int i = 0; i < size; ++i) {
        maxHeap->array->data[i] = data[i];
    }

    //Heapify
    for (int j = parent_maxHeap(size - 1); j >= 0; --j) {
        shiftDown_maxHeap(maxHeap, j);
    }

    return maxHeap;

}

int size_maxHeap(MaxHeap maxHeap) {
    return size_Arr(maxHeap->array);
}

bool isEmpty_maxHeap(MaxHeap maxHeap) {
    return size_Arr(maxHeap->array) == 0;
}

static int parent_maxHeap(int index) {

    return (index - 1) >> 1;

}

static int leftChild_maxHeap(int index) {
    return (index << 1) + 1;
}

static int rightChild_maxHeap(int index) {
    return (index << 1) + 2;
}

void add_maxHeap(MaxHeap maxHeap, VALUETYPE val) {

    if (size_Arr(maxHeap->array) == capacity_Arr(maxHeap->array)) {
        fprintf(stderr, "add:MaxHeap is full\n");
        return;
    }

    addLast_Array(maxHeap->array, val);

    shiftUp_maxHeap(maxHeap, size_Arr(maxHeap->array) - 1);
}

static void shiftUp_maxHeap(MaxHeap maxHeap, int k) {

    int parentIndex = parent_maxHeap(k);

    while (parentIndex >= 0) {

        if (maxHeap->array->data[parentIndex] < maxHeap->array->data[k]) {
            swap(maxHeap->array->data + parentIndex, maxHeap->array->data + k);
        }

        k = parentIndex;
        parentIndex = parent_maxHeap(k);

    }

}

VALUETYPE findMax_maxHeap(MaxHeap maxHeap) {
    return getEle_Array(maxHeap->array, 0);
}

VALUETYPE extractMax_maxHeap(MaxHeap maxHeap) {

    assert(!isEmpty_maxHeap(maxHeap));
    if (size_maxHeap(maxHeap) == 0) {
        fprintf(stderr, "extractMax: MaxHeap is Empty\n");
        return -1;
    }

    VALUETYPE tem = findMax_maxHeap(maxHeap);
    swap(maxHeap->array->data, maxHeap->array->data + (size_maxHeap(maxHeap) - 1));
    maxHeap->array->size--;
    shiftDown_maxHeap(maxHeap, 0);

    return tem;
}

static void shiftDown_maxHeap(MaxHeap maxHeap, int k) {

    int j;
    while (((k << 1) + 1) <= size_maxHeap(maxHeap) - 1) {

        j = (k << 1) + 1;

        // 取出左右两个孩子中最大的孩子的索引
        if (j + 1 < size_maxHeap(maxHeap) - 1 && maxHeap->array->data[j] < maxHeap->array->data[j + 1]) {
            j++;
        }

        if (maxHeap->array->data[j] < maxHeap->array->data[k]) {
            return;
        }

        swap(maxHeap->array->data + j, maxHeap->array->data + k);
        k = j;


    }


}

static void swap(VALUETYPE *v1, VALUETYPE *v2) {

    VALUETYPE temp = *v1;
    *v1 = *v2;
    *v2 = temp;

}

VALUETYPE replace_MaxHeap(MaxHeap maxHeap, VALUETYPE val) {

    VALUETYPE res = findMax_maxHeap(maxHeap);
    setEle_Array(maxHeap->array, 0, val);

    shiftDown_maxHeap(maxHeap, 0);
    return res;
}

