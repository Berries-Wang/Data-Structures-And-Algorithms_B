//
// Created by wei on 11/3/18.
//

#ifndef DSA2_MAXHEAP_H
#define DSA2_MAXHEAP_H

#include <stdbool.h>
#include "../../Array/Array.h"


#define MALLOC_MAXHEAP(TYPE, COUNT) ((TYPE*)malloc(sizeof(TYPE)*(COUNT)))

typedef struct MaxHeap *MaxHeap;

struct MaxHeap {

    Array array;

};

/**
 * 初始化一个最大堆
 * @param capacity 起始容量
 * @return  最大堆的指针
 */
MaxHeap initMaxHeap(int capacity);

/**
 * 该最大堆中元素的个数
 * @param maxHeap  最大堆的指针
 * @return  元素个数
 */
int size_MaxHeap(MaxHeap maxHeap);


/**
 * 该最大堆是否为空
 * @param maxHeap
 * @return
 */
bool isEmpty_MaxHeap(MaxHeap maxHeap);

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
 * @param maxHeap
 * @param val
 */
void add_MaxHeap(MaxHeap maxHeap, VALUETYPE val);

/**
 * 比较两个元素的大小
 * @param val1
 * @param val2
 * @return 正数(val1-val2>0) ， 0(val1-val2==0) ， 负数(val1-val2<0)
 */
static int compare_MaxHeap(VALUETYPE val1, VALUETYPE val2);

/**
 * 对指定索引的元素进行上滤操作
 * @param maxHeap  堆
 * @param index  索引
 */
static void shiftUp_MaxHeap(MaxHeap maxHeap, int index);

/**
 * 从堆中获取最大的元素
 * @param maxHeap
 * @return  最大的元素
 */
VALUETYPE extractMax_MaxHeap(MaxHeap maxHeap);


/**
 * 对指定索引的元素进行下滤
 * @param maxHeap  堆
 * @param index  即将下滤的元素的索引
 */
static void shiftDown_MaxHeap(MaxHeap maxHeap, int index);

/**
 * 将任意的数组转为最大堆
 * @param array  数组
 * @param length  数组长度
 * @return  转换后的最大堆
 */
MaxHeap heapify_MaxHeap(VALUETYPE *array, int length);


#endif //DSA2_MAXHEAP_H
