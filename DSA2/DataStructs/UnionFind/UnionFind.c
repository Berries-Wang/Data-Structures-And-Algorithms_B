//
// Created by wei on 10/6/18.
//

#include "UnionFind.h"
#include <assert.h>

UnionFind initUnionFind(int capacity) {

    UnionFind unionFind = MALLOC(struct UnionFind, 1);
    unionFind->parent = MALLOC(int, capacity);
    unionFind->rank = MALLOC(int, capacity);
    unionFind->capacity = capacity;

    for (int i = 0; i < capacity; ++i) {
        unionFind->parent[i] = i;
        unionFind->rank[i] = 1;
    }

    return unionFind;
}

void union_UF(UnionFind unionFind, int p, int q) {

    assert(p >= 0 && p < unionFind->capacity);
    assert(q >= 0 && q < unionFind->capacity);

    int pRoot = find_UF(unionFind, p);
    int qRoot = find_UF(unionFind, q);

    if (unionFind->rank[pRoot] < unionFind->rank[qRoot]) {

        unionFind->parent[pRoot] = qRoot;

    } else if (unionFind->rank[pRoot] > unionFind->rank[qRoot]) {

        unionFind->parent[qRoot] = pRoot;

    } else {

        unionFind->parent[qRoot] = pRoot;
        unionFind->rank[pRoot]++;

    }

}

int find_UF(UnionFind unionFind, int p) {

    assert(p >= 0 && p < unionFind->capacity);

    while (unionFind->parent[p] != p) {
        //路径压缩
        unionFind->parent[p] = unionFind->parent[unionFind->parent[p]];
        p = unionFind->parent[p];
    }

    return p;

}

int getSize_UF(UnionFind unionFind) {
    return unionFind->capacity;
}

bool isConnected_UF(UnionFind unionFind, int p, int q) {
    return find_UF(unionFind, p) == find_UF(unionFind, q);
}


