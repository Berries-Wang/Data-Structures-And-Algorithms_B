//
// Created by wei on 9/29/18.
//
#include "BSTSet.h"


BSTSet initBSTSet(void) {

    BSTSet bstSet = MALLOC(struct BSTSet);
    bstSet->bst = MALLOC(struct BST);

    return bstSet;

}

void add_BSTSet(BSTSet bstSet, VALUETYPE val) {

    add(bstSet->bst, val);

}

void remove_BSTSet(BSTSet bstSet, VALUETYPE val) {
    removeNode(bstSet->bst, val);
}

bool contains_BSTSet(BSTSet bstSet, VALUETYPE val) {
    return contains(bstSet->bst, val);
}

int getSize_BSTSet(BSTSet bstSet) {
    return size(bstSet->bst);
}

bool isEmpty_BSTSet(BSTSet bstSet) {
    return isEmpty(bstSet->bst);
}