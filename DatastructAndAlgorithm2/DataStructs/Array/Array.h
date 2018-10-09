//
// Created by wei on 9/22/18.
//

#ifndef DSA2_ARRAY_H
#define DSA2_ARRAY_H

#include <stdlib.h>
#include <stdbool.h>

#define  VALUETYPE int
#define  DEFAULTSIZE 10

#define  MALLOC(type, size) ((type*)malloc(sizeof(type) * size))
#define  FREE(data)  (free(data))
#define  PRINTF(value) (printf("%-4d",value))

typedef struct Array *Array;

struct Array {

    //数组
    VALUETYPE *data;
    //容量
    int capacity;
    //大小
    int size;

};

/**
 * 初始化数组
 * @param capacity 容量
 * @return  数组指针
 */
Array initArray(int);

/**
 * 获取数组元素数量
 * @return  元素数量
 */
int size_Arr(Array);

/**
 * 获取数组容量
 * @return
 */
int capacity_Arr(Array);

/**
 *
 * 向数组中指定的位置添加元素
 *
 */
void add_Array(Array, int, VALUETYPE);

/**
 * 向数组最后的位置添加元素
 */
void addLast_Array(Array, VALUETYPE);

/**
 * 向数组第一个位置添加元素
 */
void addFirst_Array(Array, VALUETYPE);

//打印数组
void show_Array(Array);

//获取指定位置的元素
VALUETYPE getEle_Array(Array, int);

//设置指定位置的元素
void setEle_Array(Array, int, VALUETYPE);

//查看数组中是否包含元素
bool contains_Array(Array, VALUETYPE);

//在数组中查找相应的元素。若存在，返回对应(第一个)索引。否则，返回-1
int find_Array(Array, VALUETYPE);

//删除指定位置上的索引
VALUETYPE remove_Array(Array, int);

//删除第一个位置上的元素
VALUETYPE removeLast_Array(Array);
//删除最后一个元素
VALUETYPE removeFirst_Array(Array);

//删除指定的元素
bool removeEle_Array(Array, VALUETYPE);

/**
 * 比较两个元素大小
 * @return  -1 前者小于后者， 0两者相等，1前者大于后者
 */
int compareTo_Array(VALUETYPE, VALUETYPE);

//对数组进行扩容/缩容
static void resize_Array(Array, int);


#endif //DSA2_ARRAY_H
