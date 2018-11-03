//
// Created by wei on 11/3/18.
//

#include <stdio.h>
#include "MaxHeap.h"
#include <time.h>

int main(int argc, char **argv) {

    srand(time(NULL));//设置随机数种子
    int count = 18;

    /*MaxHeap maxHeap = initMaxHeap(10);

    for (int i = 0; i < count; ++i) {
        add_MaxHeap(maxHeap, rand() % 1000);
    }*/

    int array[] = {1, 3, 8, 9, 6, 5, 1, 4, 7, 5, 99, 55, 88, 66, 33, 44, 77, 87};
    MaxHeap maxHeap = heapify_MaxHeap(array, count);


    int arr[count];
    for (int j = 0; j < count; ++j) {
        arr[j] = extractMax_MaxHeap(maxHeap);
        printf("%4d", arr[j]);
    }
    printf("\n");
    for (int k = 0; k < count - 1; ++k) {
        if (arr[k] < arr[k + 1]) {
            fprintf(stderr, "The MaxHeap is not Complete");
            return 0;
        }
    }

    fprintf(stdout, "The MaxHeap is Complete");

    return 0;
}

