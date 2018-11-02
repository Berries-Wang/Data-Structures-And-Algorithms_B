//
// Created by wei on 10/13/18.
//

#ifndef  DSA2_SORTALGORITHM_H
#define  DSA2_SORTALGORITHM_H

#include <algorithm>
#include "SortAlgorithmHelper.h"

namespace SortAlgorithm {

    //选择排序
    template<typename T>
    void selectSort(T array[], int length) {
        int minIndex;
        for (int i = 0; i < length; ++i) {
            minIndex = i;
            for (int j = i; j < length; ++j) {
                if (array[minIndex] > array[j]) {
                    minIndex = j;
                }
            }
            std::swap(array[minIndex], array[i]);
        }
    }

    //插入排序
    template<typename T>
    void insertSort(T array[], int length) {

        T minEle;
        int i;
        int j;

        for (i = 1; i < length; ++i) {
            minEle = array[i];
            for (j = i; j > 0 && array[j - 1] > minEle; --j) {
                array[j] = array[j - 1];
            }
            array[j] = minEle;
        }
    }

    //插入排序  对数组arr[left....Right](左闭右闭)的元素进行排序
    template<typename T>
    static void __insertSort(T array[], int left, int right) {

        int i, j;
        T temp;

        for (i = left + 1; i <= right; i++) {
            temp = array[i];
            for (j = i; j > left && temp < array[j - 1]; j--) {
                array[j] = array[j - 1];
            }

            array[j] = temp;
        }

    }

    //希尔排序
    template<typename T>
    void shellSort(T array[], int length) {

        int i, j, increment;
        T temp;

        for (increment = length / 2; increment > 0; increment /= 2) {
            for (i = increment; i < length; ++i) {
                temp = array[i];
                for (j = i; j >= increment && temp < array[j - increment]; j -= increment) {
                    array[j] = array[j - increment];
                }
                array[j] = temp;
            }
        }
    }


    //归并
    template<typename T>
    static void __merge(T array[], int left, int mid, int right, T tempMemory[]) {


        for (int i = left; i <= right; ++i) {
            tempMemory[i] = array[i];
        }

        int i = left;
        int j = mid + 1;

        for (int k = left; k <= right; ++k) {

            //这几种情况是互斥的
            //前两种是保证索引的有效性
            if (i > mid) {
                array[k] = tempMemory[j];
                j++;
            } else if (j > right) {
                array[k] = tempMemory[i];
                i++;
            } else if (tempMemory[i] < tempMemory[j]) {
                array[k] = tempMemory[i];
                i++;
            } else {
                array[k] = tempMemory[j];
                j++;
            }

        }


    }


    //对数组array[left , right](前闭后闭)范围内的元素进行排序
    template<typename T>
    static void __mergeSort(T array[], int left, int right, T tempMemory[]) {

        if (right - left <= 15) {
            __insertSort(array, left, right);
            return;
        }

        int mid = left + (right - left) / 2;

        //分
        __mergeSort(array, left, mid, tempMemory);
        __mergeSort(array, mid + 1, right, tempMemory);
        //治
        if (array[mid] > array[mid + 1]) {
            __merge(array, left, mid, right, tempMemory);
        }

    }

    //归并排序
    template<typename T>
    void mergeSort(T array[], int length) {

        T *tempMemory = new T[length];

        __mergeSort(array, 0, length - 1, tempMemory);

        SortAlgorithmHelper::destoryRandomArray(tempMemory);

    }

    /**
     * 快速排序辅助函数
     *
     * 功能:
     *    array[left....p-1]  <= array[T]
     *    array[p+1....right] >= array[T]
     */
    template<typename T>
    static int __partition(T array[], int left, int right) {

        int j = left;

        std::swap(array[left], array[rand() % (right - left + 1) + left]);

        T curC = array[left];
        //array[left+1 ....j] <= array[T]
        //array[j+1....i)  >= array[T]

        for (int i = left + 1; i <= right; ++i) {
            if (array[i] < curC) {
                std::swap(array[j + 1], array[i]);
                j++;
            }
        }

        std::swap(array[left], array[j]);
        return j;

    }

    //对数组array[left...Right](左闭右闭)区间的元素进行快速排序
    template<typename T>
    static void __quickSort(T array[], int left, int right) {

        if (right - left <= 15) {
            __insertSort(array, left, right);
            return;
        }

        int pos = __partition(array, left, right);

        __quickSort(array, left, pos - 1);
        __quickSort(array, pos + 1, right);
    }

    //快速排序
    template<typename T>
    void quickSort(T array[], int length) {
        srand(time(NULL));
        __quickSort(array, 0, length - 1);
    }


    //三路快速排序

    template<typename T>
    static void __quickSort3Ways(T array[], int left, int right) {

        if (right - left <= 15) {
            __insertSort(array, left, right);
            return;
        }

        std::swap(array[left], array[left + rand() % (right - left + 1)]);
        T curC = array[left];

        //partition
        /**
         * 定义:
         * array[left+1 ... lt] < curC
         * array[lt+1 ... i-1 ] == curC
         * array[gt ... right]  > curC
         */
        int lt = left;
        int i = left + 1;
        int gt = right + 1;

        while (i < gt) {

            if (array[i] < curC) {
                lt++;
                std::swap(array[i], array[lt]);
                i++;
            } else if (array[i] > curC) {
                gt--;
                std::swap(array[i], array[gt]);
            } else {
                i++;
            }
        }

        std::swap(array[left], array[lt]);

        __quickSort3Ways(array, left, lt - 1);
        __quickSort3Ways(array, gt, right);

    }

    template<typename T>
    void quickSort3Ways(T array[], int length) {
        srand(time(NULL));
        __quickSort3Ways(array, 0, length - 1);
    }


}


#endif

