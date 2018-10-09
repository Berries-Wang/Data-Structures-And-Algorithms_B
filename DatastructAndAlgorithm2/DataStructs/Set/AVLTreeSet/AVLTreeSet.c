//
// Created by wei on 10/9/18.
//

#include "AVLTreeSet.h"


AVLSet initAVLSet(void) {

    AVLSet set = MALLOC(struct AVLTreeSet, 1);
    set->avlTree = initAVLTree();

    return set;

}

void add_AVLSet(AVLSet set, K val) {
    add_AVLTree(set->avlTree, val, 0);
}

void remove_AVLSet(AVLSet set, K val) {
    remove_AVLTree(set->avlTree, val);
}

bool contains_AVLSet(AVLSet set, K val) {
    return contains_AVLTree(set->avlTree, val);
}

int getSize_AVLSet(AVLSet set) {
    return size(set->avlTree);

}

bool isEmpty_AVLSet(AVLSet set) {
    return isEmpty(set->avlTree);
}
