//
// Created by wei on 10/6/18.
//

#include "UnionFind.h"
#include <stdio.h>

int main(int argc, char **argv) {


    UnionFind unionFind = initUnionFind(10);

    union_UF(unionFind, 1, 0);
    printf("isConected(0,1): %d\n", isConnected_UF(unionFind, 0, 1));


    return 0;
}

