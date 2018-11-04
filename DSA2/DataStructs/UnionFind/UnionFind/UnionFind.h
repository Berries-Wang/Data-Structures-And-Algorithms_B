//
// Created by wei on 10/6/18.
//

#ifndef DSA2_UNIONFIND_H
#define DSA2_UNIONFIND_H

#include <stdlib.h>
#include <stdbool.h>

#define  MALLOC(TYPE, COUNT) ((TYPE*)malloc(sizeof(TYPE) * COUNT))
#define  FREE(HEAD) (free(HEAD))


typedef struct UnionFind *UnionFind;

struct UnionFind {

    //存储的是各个索引对应的父节点
    int *parent;
    //存储的是以索引i为根节点的树的深度.(基于Rank的优化)
    int *rank;
    //节点总数
    int capacity;

};

/**
 * 初始化并查集
 * @param capacity
 * @return
 */
UnionFind initUnionFind(int capacity);

/**
 * 将两节点合并
 * @param p
 * @param q
 */
void union_UF(UnionFind unionFind, int p, int q);

/**
 * 查找p所在的集合的编号
 * @param p
 * @return
 */
int find_UF(UnionFind unionFind, int p);

/**
 * 元素总数
 * @param unionFind
 * @return
 */
int getSize_UF(UnionFind unionFind);

/**
 * 查看是否属于同一集合
 * @param unionFind
 * @param p
 * @param q
 * @return
 */
bool isConnected_UF(UnionFind unionFind, int p, int q);

#endif //DSA2_UNIONFIND_H
