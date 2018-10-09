//
// Created by wei on 9/30/18.
//

#include "BSTMap.h"

Map initMap_BSTMap(void) {

    Map map = MALLOC(struct BSTMap);
    map->bst = MALLOC(struct BST);

    return map;

}

void add_BSTMap(Map map, K key, V val) {

    add(map->bst, key, val);

}

void remove_BSTMap(Map map, K key) {
    removeNode(map->bst, key);
}


bool contains_BSTMap(Map map, K key) {
    return contains(map->bst, key);
}

V get_BSTMap(Map map, K key) {
    return get_BST(map->bst, key);
}

void set_BSTMap(Map map, K key, V val) {
    set_BST(map->bst, key, val);
}

int getSize_BSTMap(Map map) {
    return map->bst->size;
}

bool isEmpty_BSTMap(Map map) {

    return isEmpty(map->bst);

}




