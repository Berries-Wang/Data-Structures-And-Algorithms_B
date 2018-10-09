//
// Created by wei on 10/9/18.
//

#ifndef DSA2_AVLTREESET_H
#define DSA2_AVLTREESET_H


#include "AVLTree.h"

typedef struct AVLTreeSet *AVLSet;

struct AVLTreeSet {
    AVLTree avlTree;
};

/**
 * 创建一个集合
 * @return
 */
AVLSet initAVLSet(void);

/**
 * 添加元素
 * @param AVLSet
 * @param val
 */
void add_AVLSet(AVLSet set, K val);

/**
 * 删除元素
 * @param AVLSet
 * @param val
 */
void remove_AVLSet(AVLSet set, K val);

/**
 * 是否包含元素
 * @param AVLSet
 * @param val
 * @return
 */
bool contains_AVLSet(AVLSet set, K val);

/**
 * 获取元素数
 * @param AVLSet
 * @return
 */
int getSize_AVLSet(AVLSet set);

/**
 * 集合是否为空
 * @param AVLSet
 * @return
 */
bool isEmpty_AVLSet(AVLSet set);


#endif //DSA2_AVLTREESET_H
