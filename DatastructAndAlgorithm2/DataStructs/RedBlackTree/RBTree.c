//
// Created by wei on 10/9/18.
//

#include "RBTree.h"
#include <string.h>

static Node createNode_RBTree(K key, V val) {

    Node newNode = MALLOC(struct RBNode, 1);

    newNode->key = key;
    newNode->value = val;
    newNode->left = newNode->right = NULL;
    newNode->color = RBT_RED; //因为默认插入红色节点

    return newNode;

}

RBTree initRBTree(void) {

    RBTree rbTree = MALLOC(struct RBTree, 1);
    rbTree->size = 0;
    rbTree->root = NULL;

    return rbTree;

}

static int compare(K k1, K k2) {

    int len1 = strlen(k1);
    int len2 = strlen(k2);

    int cur = len1 > len2 ? len2 : len1;

    for (int i = 0; i < cur; i++) {
        if (k1[i] != k2[i]) {
            return k1[i] - k2[i];
        }
    }

    return 0;

}

static int compareTo_Helper(K key1, K key2, int(*compare)(K, K)) {
    return compare(key1, key2);
}


static int compareTo(K key1, K key2) {
    return compareTo_Helper(key1, key2, compare);
}

int size_RB(RBTree rbTree) {
    return rbTree->size;
}

bool isEmpty_RB(RBTree rbTree) {
    return size_RB(rbTree) == 0;
}

V get_RB(RBTree rbTree, K key) {
    return get_RB_static(rbTree->root, key);
}

static V get_RB_static(Node node, K key) {

    if (node == NULL) {
        return INVALIDVALUE;
    }

    if (compareTo(node->key, key) < 0) {
        return get_RB_static(node->right, key);
    } else if (compareTo(node->key, key) > 0) {
        return get_RB_static(node->left, key);
    } else {
        return node->value;
    }

}

bool constains_RB(RBTree rbTree, K key) {
    return contains_RB_static(rbTree->root, key);
}

static bool contains_RB_static(Node node, K key) {
    if (node == NULL) {
        return false;
    }

    if (compareTo(node->key, key) < 0) {
        return contains_RB_static(node->right, key);
    } else if (compareTo(node->key, key) > 0) {
        return contains_RB_static(node->left, key);
    } else {
        return false;
    }
}


bool set_RB(RBTree rbTree, K key, V val) {
    return set_RB_static(rbTree->root, key, val);
}

static bool set_RB_static(Node node, K key, V val) {

    if (node == NULL) {
        return false;
    }

    if (compareTo(node->key, key) < 0) {
        return set_RB_static(node->right, key, val);
    } else if (compareTo(node->key, key) > 0) {
        return set_RB_static(node->left, key, val);
    } else {
        node->value = val;
        return true;
    }

}

//   node                     x
//  /   \     左旋转         /  \
// T1   x   --------->   node   T3
//     / \              /   \
//    T2 T3            T1   T2
static Node rotateWithLeft(Node node) {

    Node retNode = node->right;
    node->right = retNode->left;
    retNode->left = node;

    retNode->color = node->color;
    node->color = RBT_RED;

    return retNode;

}

//     node                   x
//    /   \     右旋转       /  \
//   x    T2   ------->   y   node
//  / \                       /  \
// y  T1                     T1  T2
static Node rotateWithRight(Node node) {

    Node retNode = node->left;
    node->left = retNode->right;
    retNode->right = node;

    retNode->color = node->color;
    node->color = RBT_RED;

    return retNode;

}

static bool isRed(Node node) {

    if (node == NULL) {
        return RBT_BLACK;
    } else {
        return node->color;
    }

}

static void fliperColor(Node node) {

    node->color = RBT_RED;
    node->left->color = RBT_BLACK;
    node->right->color = RBT_BLACK;

}


void addNode_RB(RBTree rbTree, K key, V val) {

    rbTree->root = addNode_RB_static(rbTree, rbTree->root, key, val);
    //红黑树的根是黑色的
    rbTree->root->color = RBT_BLACK;

}

static Node addNode_RB_static(RBTree rbTree, Node node, K key, V val) {

    if (node == NULL) {
        Node newNode = createNode_RBTree(key, val);
        rbTree->size++;
        return newNode;
    }

    if (compareTo(node->key, key) < 0) {
        node->right = addNode_RB_static(rbTree, node->right, key, val);
    } else if (compareTo(node->key, key) > 0) {
        node->left = addNode_RB_static(rbTree, node->left, key, val);
    } else {
        node->value = val;
    }

    //节点添加完毕后回溯向上维护红黑树的性质
    if (!isRed(node->left) && isRed(node->right)) { // 左旋转
        node = rotateWithLeft(node);
    }

    if (isRed(node->left) && isRed(node->left->left)) { //右旋转
        node = rotateWithRight(node);
    }

    if (isRed(node->left) && isRed(node->right)) { //颜色翻转
        fliperColor(node);
    }

    return node;


}