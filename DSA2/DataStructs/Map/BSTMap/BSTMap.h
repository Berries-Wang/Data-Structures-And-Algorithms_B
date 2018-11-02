//
// Created by wei on 9/30/18.
//

#ifndef DSA2_BSTMAP_H
#define DSA2_BSTMAP_H

#include "BST.h"


typedef struct BSTMap *Map;

struct BSTMap {

    BST bst;

};

/**
 * 初始化一个映射
 * @return
 */
Map initMap_BSTMap(void);

/**
 * 添加键值对
 * @param map
 * @param key
 * @param val
 */
void add_BSTMap(Map map, K key, V val);

/**
 * 移除键值对
 * @param map
 * @param key
 * @return
 */
void remove_BSTMap(Map map, K key);

/**
 * 是否包含键为key的节点
 * @param map
 * @param key
 * @return
 */
bool contains_BSTMap(Map map, K key);


/**
 * 根据键来获取值
 * @param map
 * @param key
 * @return
 */
V get_BSTMap(Map map, K key);

/**
 * 根据键来设置节点的值
 * @param map
 * @param key
 * @param val
 */
void set_BSTMap(Map map, K key, V val);

/**
 * 获取映射中元素的个数
 * @param map
 * @return
 */
int getSize_BSTMap(Map map);

/**
 * 映射是否为空
 * @param map
 * @return
 */
bool isEmpty_BSTMap(Map map);

#endif //DSA2_BSTMAP_H
