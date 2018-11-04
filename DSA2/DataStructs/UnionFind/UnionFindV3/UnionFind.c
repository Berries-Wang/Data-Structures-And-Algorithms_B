//
// Created by wei on 11/3/18.
//

#include "UnionFind.h"
#include <assert.h>

UnionFind initUnionFindV1(int capacity) {

    UnionFind unionFind = MALLOC(struct UnionFind, 1);
    unionFind->size = capacity;
    unionFind->parent = MALLOC(int, capacity);
    unionFind->sz = MALLOC(int, capacity);

    for (int i = 0; i < capacity; ++i) {
        unionFind->parent[i] = i;
        unionFind->sz[i] = 1;
    }

    return unionFind;

}


int size_UnionFindV1(UnionFind unionFind) {

    assert(unionFind != NULL);

    return unionFind->size;
}

static int find_UnionFindV1(UnionFind unionFind, int p) {

    assert(p >= 0 && p < size_UnionFindV1(unionFind));

    while (p != unionFind->parent[p]) {
        p = unionFind->parent[p];
    }

    return p;
}


bool isConnected(UnionFind unionFind, int p, int q) {

    return find_UnionFindV1(unionFind, p) == find_UnionFindV1(unionFind, q);

}

void unionEle(UnionFind unionFind, int p, int q) {

    int cq = find_UnionFindV1(unionFind, q);
    int cp = find_UnionFindV1(unionFind, p);
    //先判断这两个元素是否已经连接
    if (cp == cq) {
        return;
    }

    if (unionFind->sz[cp] > unionFind->sz[cq]) {
        unionFind->parent[cq] = cp;
        unionFind->sz[cp] += unionFind->sz[cq];
    } else {
        unionFind->parent[cp] = cq;
        unionFind->sz[cq] += unionFind->sz[cp];
    }
}