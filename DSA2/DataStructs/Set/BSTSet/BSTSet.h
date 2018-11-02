//
// Created by wei on 9/29/18.
//

#ifndef DSA2_BSTSET_H
#define DSA2_BSTSET_H

#include "../../BinarySearchTree/BST.h"

typedef struct BSTSet *BSTSet;

struct BSTSet {

    BST bst;

};

/**
 * 创建一个集合
 * @return
 */
BSTSet initBSTSet(void);

/**
 * 添加元素
 * @param bstSet
 * @param val
 */
void add_BSTSet(BSTSet bstSet, VALUETYPE val);

/**
 * 删除元素
 * @param bstSet
 * @param val
 */
void remove_BSTSet(BSTSet bstSet, VALUETYPE val);

/**
 * 是否包含元素
 * @param bstSet
 * @param val
 * @return
 */
bool contains_BSTSet(BSTSet bstSet, VALUETYPE val);

/**
 * 获取元素数
 * @param bstSet
 * @return
 */
int getSize_BSTSet(BSTSet bstSet);

/**
 * 集合是否为空
 * @param bstSet
 * @return
 */
bool isEmpty_BSTSet(BSTSet bstSet);


#endif //DSA2_BSTSET_H
