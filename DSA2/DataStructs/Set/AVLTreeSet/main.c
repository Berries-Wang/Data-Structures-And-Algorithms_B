//
// Created by wei on 10/9/18.
//

#include "AVLTreeSet.h"

int main(int argc, char **argv) {


    char *strs[] = {"Hello1", "World2", "Hello3", "World4", "Hello5", "World6", "Hello7", "World8", "Hello9"};
    char **strss = strs;

    AVLSet set = initAVLSet();

    for (int i = 0; i < sizeof(strs) / sizeof(char *); ++i) {
        add_AVLSet(set, strss[i]);
    }

    inOrder_AVLTree(set->avlTree);

    return 0;
}

