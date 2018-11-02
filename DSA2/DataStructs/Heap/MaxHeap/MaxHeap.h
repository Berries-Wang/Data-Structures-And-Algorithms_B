//
// Created by wei on 9/30/18.
//

#ifndef DSA2_MAXHEAP_H
#define DSA2_MAXHEAP_H

#include "../../Array/Array.h"


typedef struct MaxHeap *MaxHeap;

struct MaxHeap {
    Array array;
};

/**
 * 初始化一个最大堆
 * @return
 */
MaxHeap initMaxHeap(int capacity);

/**
 * 根据一个数组来创建二叉堆
 * @param data
 * @param size
 * @return
 */
MaxHeap initMaxHeap_byArr(VALUETYPE *data, int size);

//堆中元素个数
int size_maxHeap(MaxHeap maxHeap);

// 返回一个布尔值, 表示堆中是否为空
bool isEmpty_maxHeap(MaxHeap maxHeap);

// 返回完全二叉树的数组表示中，一个索引所表示的元素的父亲节点的索引
static int parent_maxHeap(int index);

// 返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
static int leftChild_maxHeap(int index);


// 返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引
static int rightChild_maxHeap(int index);


// 向堆中添加元素
void add_maxHeap(MaxHeap maxHeap, VALUETYPE val);

//上滤
static void shiftUp_maxHeap(MaxHeap maxHeap, int k);

//找到堆中最大值
VALUETYPE findMax_maxHeap(MaxHeap maxHeap);

// 取出堆中最大元素
VALUETYPE extractMax_maxHeap(MaxHeap maxHeap);

//下滤
static void shiftDown_maxHeap(MaxHeap maxHeap, int k);

//元素交换
static void swap(VALUETYPE *v1, VALUETYPE *v2);

//将val替换堆顶元素，返回替换之前的堆定元素
VALUETYPE replace_MaxHeap(MaxHeap maxHeap, VALUETYPE val);

#endif //DSA2_MAXHEAP_H


