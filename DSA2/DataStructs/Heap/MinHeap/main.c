//
// Created by wei on 11/3/18.
//

#include "MinHeap.h"
#include <stdio.h>
#include <time.h>


int main(int argc, char **argv) {

    srand(time(NULL));

    int count = 300;

    MinHeap minHeap = initMinHeap(count);

    for (int i = 0; i < count; ++i) {
        add_MinHeap(minHeap, rand() % 100);
    }

    int arrTest[count];
    for (int j = 0; j < count; ++j) {
        arrTest[j] = extractMin_MinHeap(minHeap);
    }

    for (int k = 0; k < count - 1; ++k) {
        if (arrTest[k] > arrTest[k + 1]) {
            fprintf(stderr, "MinHeap is not Complete\n");
            return 0;
        }
    }

    fprintf(stdout, "MinHeap is Complete\n");

    return 0;
}