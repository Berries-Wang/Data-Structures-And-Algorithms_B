//
// Created by wei on 9/30/18.
//

#include "MaxHeap.h"
#include <stdio.h>


int main(int argc, char **argv) {

    MaxHeap maxHeap = initMaxHeap(11);

    for (int i = 0; i < 11; ++i) {
        add_maxHeap(maxHeap, i);
    }
    show_Array(maxHeap->array);
    for (int i = 0; i < 11; ++i) {
        int val = extractMax_maxHeap(maxHeap);
        printf("%-3d", val);
    }

    printf("\n\n\n\n\n");

    VALUETYPE data[] = {1, 3, 2, 5, 6, 4, 9, 8, 7, 0};
    MaxHeap maxHeap1 = initMaxHeap_byArr(data, 10);
    VALUETYPE ret = replace_MaxHeap(maxHeap1, -1);
    PRINTF(ret);
    printf("\n");
    for (int i = 0; i < maxHeap1->array->capacity; ++i) {
        int val = extractMax_maxHeap(maxHeap1);
        printf("%-3d", val);
    }

    printf("\n\n\n\n\n");

    return 0;
}