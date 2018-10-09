//
// Created by wei on 9/22/18.
//
#include "Array.h"
#include <stdio.h>

Array initArray(int capacity) {

    if (capacity < DEFAULTSIZE) {
        capacity = DEFAULTSIZE;
    }

    Array array = MALLOC(struct Array, 1);
    array->size = 0;
    array->capacity = capacity;
    array->data = MALLOC(VALUETYPE, array->capacity);

    return array;

}

int size_Arr(Array array) {

    return array->size;

}

int capacity_Arr(Array array) {
    return array->capacity;
}

void add_Array(Array array, int index, VALUETYPE val) {

    if (index < 0 || index > array->size) {
        fprintf(stderr, "Illegal index .index should be > %d  and <= %d\n", 0, array->size);
        return;
    }

    if (array->size == array->capacity) { // 需要进行扩容
        resize_Array(array, array->capacity * 2);
    }

    for (int i = array->size - 1; i >= index; i--) {
        array->data[i + 1] = array->data[i];
    }

    array->data[index] = val;
    array->size++;

}

void addLast_Array(Array array, VALUETYPE val) {

    add_Array(array, array->size, val);

}

void addFirst_Array(Array array, VALUETYPE val) {

    add_Array(array, 0, val);

}


void show_Array(Array array) {

    printf("Array: Size: %d , Capacity: %d.\n Eles:", array->size, array->capacity);

    for (int i = 0, end = array->size; i < end; i++) {
        PRINTF(array->data[i]);
    }
    printf("\n");

}


VALUETYPE getEle_Array(Array array, int index) {

    int size = array->size;

    if (index < 0 || index >= size) {
        fprintf(stderr, "Illegal index .index should be > %d  and < %d\n", 0, size);
    }

    return array->data[index];


}

void setEle_Array(Array array, int index, VALUETYPE val) {
    int size = array->size;

    if (index < 0 || index >= size) {
        fprintf(stderr, "Illegal index .index should be > %d  and < %d\n", 0, size);
    }

    array->data[index] = val;
}


bool contains_Array(Array array, VALUETYPE val) {

    for (int i = 0, end = array->size; i < end; i++) {
        if (array->data[i] == val) {
            return true;
        }

    }
    return false;
}

int find_Array(Array array, VALUETYPE val) {

    for (int i = 0, end = array->size; i < end; i++) {
        if (array->data[i] == val) {
            return i;
        }

    }
    return -1;
}

VALUETYPE remove_Array(Array array, int index) {

    int end = array->size;

    if (index < 0 || index >= end) {
        fprintf(stderr, "Illegal index .index should be > %d  and < %d\n", 0, end);
    } else {
        array->size--;
    }


    VALUETYPE res = array->data[index];
    for (int i = index; i < end - 1; ++i) {
        //将元素向前移动
        array->data[i] = array->data[i + 1];
    }

    /**
     *
     * 当数组元素个数等于容量时，此时，再addLast一个元素之后立即移除removeLast一个元素，此时会进行以此扩容以此缩容，
     * 从而造成复杂度的震荡
     */
    //此种缩容策略是避免复杂度震荡----当数组元素数量为数组容量的四分之一时，才缩容到原来的一半。
    if (end == array->capacity / 4 && array->capacity / 2 != 0) {
        resize_Array(array, array->capacity / 2);
    }

    return res;
}

VALUETYPE removeLast_Array(Array array) {
    return remove_Array(array, array->size - 1);
}

VALUETYPE removeFirst_Array(Array array) {
    return remove_Array(array, 0);
}


bool removeEle_Array(Array array, VALUETYPE val) {

    int index = find_Array(array, val);

    if (index > -1) {
        remove_Array(array, index);
        return true;
    }

    return false;
}

int compareTo_Array(VALUETYPE val1, VALUETYPE val2) {

    return val1 - val2;

}


static void resize_Array(Array array, int newCapacity) {

    VALUETYPE *newData = MALLOC(VALUETYPE, newCapacity);

    for (int i = 0; i < array->size; ++i) {
        newData[i] = array->data[i];
    }
    FREE(array->data);
    array->data = newData;
    array->capacity = newCapacity;
}



