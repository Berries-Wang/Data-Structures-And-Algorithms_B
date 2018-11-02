//
// Created by wei on 10/9/18.
//

#ifndef DSA2_AVLTREEMAP_H
#define DSA2_AVLTREEMAP_H

#include "AVLTree.h"

typedef struct AVLTreeMap *Map;


struct AVLTreeMap {

    AVLTree avlTree;

};

/**
 * 初始化一个映射
 * @return
 */
Map initMap_AVLMap(void);

/**
 * 添加键值对
 * @param map
 * @param key
 * @param val
 */
void add_AVLMap(Map map, K key, V val);

/**
 * 移除键值对
 * @param map
 * @param key
 * @return
 */
void remove_AVLMap(Map map, K key);

/**
 * 是否包含键为key的节点
 * @param map
 * @param key
 * @return
 */
bool contains_AVLMap(Map map, K key);


/**
 * 根据键来获取值
 * @param map
 * @param key
 * @return
 */
V get_AVLMap(Map map, K key);

/**
 * 根据键来设置节点的值
 * @param map
 * @param key
 * @param val
 */
void set_AVLMap(Map map, K key, V val);

/**
 * 获取映射中元素的个数
 * @param map
 * @return
 */
int getSize_AVLMap(Map map);

/**
 * 映射是否为空
 * @param map
 * @return
 */
bool isEmpty_AVLMap(Map map);

#endif //DSA2_AVLTREEMAP_H
