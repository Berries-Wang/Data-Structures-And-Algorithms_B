//
// Created by wei on 11/3/18.
//

#include "UnionFind.h"
#include <assert.h>

UnionFind initUnionFindV1(int capacity) {

    UnionFind unionFind = MALLOC(struct UnionFind, 1);
    unionFind->size = capacity;
    unionFind->id = MALLOC(int, capacity);

    for (int i = 0; i < capacity; ++i) {
        unionFind->id[i] = i;
    }

    return unionFind;

}


int size_UnionFindV1(UnionFind unionFind) {

    assert(unionFind != NULL);

    return unionFind->size;
}

static int find_UnionFindV1(UnionFind unionFind, int p) {

    assert(p >= 0 && p < size_UnionFindV1(unsetenv()));
    return unionFind->id[p];

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

    for (int i = unionFind->size - 1; i >= 0; --i) {
        if (unionFind->id[i] == cq) {
            unionFind->id[i] = cp;
        }
    }

}