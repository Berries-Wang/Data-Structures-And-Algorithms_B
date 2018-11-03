//
// Created by wei on 11/3/18.
//

#include "MaxHeap.h"
#include <stdio.h>

MaxHeap initMaxHeap(int capacity) {

    MaxHeap maxHeap = MALLOC_MAXHEAP(struct MaxHeap, 1);
    maxHeap->array = initArray(capacity);

    return maxHeap;
}


int size_MaxHeap(MaxHeap maxHeap) {

    if (maxHeap == NULL) {
        return -1;
    }

    return size_Arr(maxHeap->array);
}

bool isEmpty_MaxHeap(MaxHeap maxHeap) {

    if (maxHeap == NULL) {
        return -1;
    }

    return maxHeap->array->size == 0;

}

static int parent(int index) {

    if (index == 0) {
        return index;
    }

    return (index - 1) >> 1;

}

static int leftChild(int index) {

    return (index << 1) + 1;

}

static int compare_MaxHeap(VALUETYPE val1, VALUETYPE val2) {
    return val1 - val2;
}

static int rightChild(int index) {
    return (index << 1) + 2;
}

void add_MaxHeap(MaxHeap maxHeap, VALUETYPE val) {

    addLast_Array(maxHeap->array, val);
    //进行上滤
    shiftUp_MaxHeap(maxHeap, size_MaxHeap(maxHeap) - 1);

}


static void shiftUp_MaxHeap(MaxHeap maxHeap, int index) {

    //当index索引对应的元素大于其父节点的值时才进行操作
    while (index > 0 &&
           compare_MaxHeap(getEle_Array(maxHeap->array, index), getEle_Array(maxHeap->array, parent(index))) > 0) {

        swap_array(maxHeap->array, index, parent(index));
        index = parent(index);
    }

}


VALUETYPE extractMax_MaxHeap(MaxHeap maxHeap) {

    if (size_MaxHeap(maxHeap) == 0) {
        fprintf(stderr, "Index Out Of Bound Exception On extractMax_MaxHeap");
        return 0;
    }

    VALUETYPE res = getEle_Array(maxHeap->array, 0);

    //将堆中最后一个元素放到第一个位置， 再进行下滤操作
    swap_array(maxHeap->array, 0, size_Arr(maxHeap->array) - 1);
    removeLast_Array(maxHeap->array);
    shiftDown_MaxHeap(maxHeap, 0);

    return res;

}

static void shiftDown_MaxHeap(MaxHeap maxHeap, int index) {

    int j = -1;
    int size = size_MaxHeap(maxHeap);
    while (leftChild(index) < size) {  //保证拥有左孩子
        j = leftChild(index);
        //在保证不越界的情况下，当右孩子的值大于左孩子时维护j的值
        if (j + 1 < size && compare_MaxHeap(getEle_Array(maxHeap->array, j), getEle_Array(maxHeap->array, j + 1)) < 0) {
            j = j + 1;
        }

        if (compare_MaxHeap(getEle_Array(maxHeap->array, index), getEle_Array(maxHeap->array, j)) >= 0) {
            return;
        }

        swap_array(maxHeap->array, index, j);
        index = j;
    }

}

MaxHeap heapify_MaxHeap(VALUETYPE *array, int length) {

    if (array == NULL) {
        fprintf(stderr, "The Array is not be NULL");
        return NULL;
    }

    MaxHeap maxHeap = initMaxHeap(length);
    for (int j = 0; j < length; ++j) {
        maxHeap->array->data[j] = array[j];
        maxHeap->array->size = j + 1;
    }

    array = NULL;

    //从最后一个非叶子节点开始，进行下滤操作
    for (int i = parent(length - 1); i >= 0; --i) {
        shiftDown_MaxHeap(maxHeap, i);
    }

    return maxHeap;
}


