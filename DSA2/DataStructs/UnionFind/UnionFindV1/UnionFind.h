//
// Created by wei on 11/3/18.
//

#ifndef DSA2_UNIONFIND_H
#define DSA2_UNIONFIND_H

#include <stdlib.h>
#include <stdbool.h>

#define MALLOC(TYPE, COUNT) (malloc(sizeof(TYPE)*(COUNT)))

typedef struct UnionFind *UnionFind;

struct UnionFind {

    int *id;
    int size;

};

/**
 * 初始化一个并查集
 * @param capacity 数组容量（元素个数）
 * @return  并查集
 */
UnionFind initUnionFindV1(int capacity);

/**
 * 查看并查集中元素个数
 * @param unionFind
 * @return
 */
int size_UnionFindV1(UnionFind unionFind);


/**
 * 查看这个节点是属于哪一方的（属于哪一个集合）
 * @param p
 * @return
 */
static int find_UnionFindV1(UnionFind unionFind, int p);

/**
 * 判断两个元素是否连接
 * @param unionFind
 * @param p
 * @param q
 * @return
 */
bool isConnected(UnionFind unionFind, int p, int q);

/**
 * 使两个元素连接
 * @param unionFind
 * @param p
 * @param q
 */
void unionEle(UnionFind unionFind, int p, int q);

#endif //DSA2_UNIONFIND_H
