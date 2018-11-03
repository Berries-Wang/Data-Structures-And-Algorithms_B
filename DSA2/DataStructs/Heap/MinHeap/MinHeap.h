//
// Created by wei on 11/3/18.
//

#ifndef DSA2_MINHEAP_H
#define DSA2_MINHEAP_H

#include <stdbool.h>
#include "../../Array/Array.h"

typedef struct MinHeap *MinHeap;


struct MinHeap {
    Array array;
};

/**
 * 初始化一个最小堆
 * @param capacity 起始容量
 * @return  最小堆的指针
 */
MinHeap initMinHeap(int capacity);

/**
 * 该最小堆中元素的个数
 * @param MinHeap  最小堆的指针
 * @return  元素个数
 */
int size_MinHeap(MinHeap minHeap);


/**
 * 该最小堆是否为空
 * @param MinHeap
 * @return
 */
bool isEmpty_MinHeap(MinHeap minHeap);

/**
 * 计算索引为index的节点的父节点的索引
 * @param index   子节索引
 * @return  父节点索引
 */
static int parent(int index);


/**
 *计算索引为index的节点的左孩子节点的索引
 * @param index  父节点索引
 * @return  左孩子节点索引
 */
static int leftChild(int index);


/**
 * 计算索引为index的节点的右孩子节点的索引
 * @param index  父节点索引
 * @return  右孩子节点索引
 */
static int rightChild(int index);

/**
 * 添加元素到堆中
 * @param MinHeap
 * @param val
 */
void add_MinHeap(MinHeap minHeap, VALUETYPE val);

/**
 * 比较两个元素的大小
 * @param val1
 * @param val2
 * @return 正数(val1-val2>0) ， 0(val1-val2==0) ， 负数(val1-val2<0)
 */
static int compare_MinHeap(VALUETYPE val1, VALUETYPE val2);

/**
 * 对指定索引的元素进行上滤操作
 * @param MinHeap  堆
 * @param index  索引
 */
static void shiftUp_MinHeap(MinHeap minHeap, int index);

/**
 * 从堆中获取最大的元素
 * @param MinHeap
 * @return  最大的元素
 */
VALUETYPE extractMin_MinHeap(MinHeap minHeap);


/**
 * 对指定索引的元素进行下滤
 * @param MinHeap  堆
 * @param index  即将下滤的元素的索引
 */
static void shiftDown_MinHeap(MinHeap minHeap, int index);

/**
 * 将任意的数组转为最小堆
 * @param array  数组
 * @param length  数组长度
 * @return  转换后的最小堆
 */
MinHeap heapify_MinHeap(VALUETYPE *array, int length);

#endif //DSA2_MINHEAP_H
