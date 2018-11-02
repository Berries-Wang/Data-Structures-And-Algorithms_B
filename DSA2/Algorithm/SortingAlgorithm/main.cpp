//
// Created by wei on 10/13/18.
//


#include <iostream>
#include "SortAlgorithmHelper.h"
#include "SortAlgorithm.h"

int main(int argc, char **argv) {

    int length = 10000000;
    int rangeL = 0;
    int rangeR = 10000000;


    int *arr = SortAlgorithmHelper::generateRandomArray(length, rangeL, rangeR);
    //int *arr = SortAlgorithmHelper::generateNearlyOrderedArray(length, 100);
    int *arr4 = SortAlgorithmHelper::copyArray(arr, length);
    int *arr5 = SortAlgorithmHelper::copyArray(arr, length);

    SortAlgorithmHelper::test("归并排序", SortAlgorithm::mergeSort, arr4, length);
   // SortAlgorithmHelper::test("快速排序", SortAlgorithm::quickSort, arr5, length);
    SortAlgorithmHelper::test("三路快速排序", SortAlgorithm::quickSort3Ways, arr, length);

    SortAlgorithmHelper::destoryRandomArray(arr);
    SortAlgorithmHelper::destoryRandomArray(arr5);
    SortAlgorithmHelper::destoryRandomArray(arr4);

    // 6217 0021 0000 5140 843

    return 0;
}
