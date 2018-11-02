//
// Created by wei on 10/13/18.
//

#ifndef DSA2_SORTALGORITHMHELPER_H
#define DSA2_SORTALGORITHMHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

namespace SortAlgorithmHelper {

    /**
     * 产生随机数数组
     * @param size  要产生的数组大小
     * @param RangeL  数组的左边界
     * @param RandeR  数组的右边界
     * @return  产生的数组
     */
    int *generateRandomArray(int size, int RangeL, int RandeR) {

        //设置随机化种子
        srand(time(NULL));
        int *array = new int[size];

        for (int i = 0; i < size; ++i) {
            array[i] = rand() % (RandeR - RangeL + 1) + RangeL;
        }

        return array;
    }

    /**
     * 销毁随机数数组
     * @param delArr
     */
    void destoryRandomArray(int delArr[]) {
        delete[] delArr;
        delArr = nullptr;
    }

    /**
     * 打印数组
     * @tparam T
     * @param array
     * @param length
     */
    template<typename T>
    void printfArray(T array[], int length) {

        for (int i = 0; i < length; ++i) {
            std::cout << array[i] << "   ";
        }

        std::cout << std::endl;
    }


    /**
     * 判断数组是否有序
     */
    template<typename T>
    bool isSorted(T arr[], int length) {

        for (int i = 0; i < length - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }

        return true;
    }


    /**
     * 排序算法的性能测试
     * @tparam T  数组类型
     * @param name  排序算法名
     * @param sort  排序算法函数指针
     * @param array  要排序的数组
     * @param length  数组的大小
     */
    template<typename T>
    void test(char *name, void(*sort)(T array[], int length), T array[], int length) {

        clock_t start = clock();

        sort(array, length);

        clock_t end = clock();

        assert(isSorted(array, length));

        double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

        std::cout << name << " ： " << time << " s" << std::endl;
    }

    template<typename T>
    T *copyArray(T array[], int length) {

        T *newArr = new T[length];
        for (int i = 0; i < length; ++i) {
            newArr[i] = array[i];
        }
        return newArr;
    }

    /**
     * 产生一个近乎有序的数组
     *    先产生一个完全有序的数组，再随机交换几对数字
     * @param length  数组长度
     * @param swapTimes  交换几次
     * @return
     */
    int *generateNearlyOrderedArray(int length, int swapTimes) {

        int *array = new int[length];

        for (int i = 0; i < length; ++i) {
            array[i] = 0;
        }

        for (int j = 0; j < swapTimes; ++j) {

            int l = rand() % length;
            int r = rand() % length;

            std::swap(array[l], array[r]);

        }

        return array;

    }

}


#endif //DSA2_SORTALGORITHMHELPER_H
