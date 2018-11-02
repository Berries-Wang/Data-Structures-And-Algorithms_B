//
// Created by wei on 10/9/18.
//

#include "AVLTreeMap.h"

Map initMap_AVLMap(void) {

    Map map = MALLOC(struct AVLTreeMap, 1);
    map->avlTree = initAVLTree();

    return map;

}

void add_AVLMap(Map map, K key, V val) {
    add_AVLTree(map->avlTree, key, val);
}

void remove_AVLMap(Map map, K key) {

    remove_AVLTree(map->avlTree, key);

}


bool contains_AVLMap(Map map, K key) {

    return contains_AVLTree(map->avlTree, key);

}

V get_AVLMap(Map map, K key) {

    return get_AVLTree(map->avlTree, key);

}

void set_AVLMap(Map map, K key, V val) {

    set_AVLTree(map->avlTree, key, val);

}

int getSize_AVLMap(Map map) {
    return map->avlTree->size;
}

bool isEmpty_AVLMap(Map map) {
    return isEmpty(map->avlTree);
}