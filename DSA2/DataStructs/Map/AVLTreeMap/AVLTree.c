//
// Created by wei on 10/8/18.
//
#include "AVLTree.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>


AVLTree initAVLTree(void) {

    AVLTree avlTree = MALLOC(struct AVLTree, 1);
    avlTree->size = 0;
    avlTree->root = NULL;

    return avlTree;

}


static Node createNode_AVLTree_static(K key, V value) {

    Node newNode = MALLOC(struct Node, 1);
    newNode->key = key;
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

static int getHeight_AVLTree_static(Node node) {

    if (node == NULL) { //空节点的高度为0
        return 0;
    }

    return node->height;

}

int getBalanceFactro_AVLTree(Node node) {

    if (node == NULL) {
        return 0;
    }

    return getHeight_AVLTree_static(node->left) - getHeight_AVLTree_static(node->right);
}


int size(AVLTree avlTree) {
    return avlTree->size;
}

bool isEmpty(AVLTree avlTree) {
    return avlTree->size == 0;
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


static Node sigleRotateWithRight(Node node) {

    Node tempNode = node->left;
    node->left = tempNode->right;
    tempNode->right = node;

    //维护高度
    node->height = 1 + MAX(getHeight_AVLTree_static(node->left), getHeight_AVLTree_static(node->right));
    tempNode->height = 1 + MAX(getHeight_AVLTree_static(tempNode->left), getHeight_AVLTree_static(tempNode->right));

    return tempNode;

}

static Node sigleRotateWithLeft(Node node) {

    Node tempNode = node->right;
    node->right = tempNode->left;
    tempNode->left = node;


    //维护高度
    node->height = 1 + MAX(getHeight_AVLTree_static(node->left), getHeight_AVLTree_static(node->right));
    tempNode->height = 1 + MAX(getHeight_AVLTree_static(tempNode->left), getHeight_AVLTree_static(tempNode->right));


    return tempNode;

}

void add_AVLTree(AVLTree avlTree, K key, V value) {
    avlTree->root = add_Node_AVLTree_static(avlTree, avlTree->root, key, value);
}

static Node add_Node_AVLTree_static(AVLTree avlTree, Node node, K key, V value) {

    if (node == NULL) {
        Node newNode = createNode_AVLTree_static(key, value);
        avlTree->size++;
        return newNode;
    }

    if (compareTo(node->key, key) < 0) {

        node->right = add_Node_AVLTree_static(avlTree, node->right, key, value);

    } else if (compareTo(node->key, key) > 0) {

        node->left = add_Node_AVLTree_static(avlTree, node->left, key, value);

    } else {//compareTo(node->key, key) == 0

        node->value = value;

    }

    //维护节点的height的值
    node->height = 1 + MAX(getHeight_AVLTree_static(node->left), getHeight_AVLTree_static(node->right));

    //获取平衡因子
    int balanceFactor = getBalanceFactro_AVLTree(node);

    //进行平衡
    /**
     * 1.确定是要进行平衡
     * 2.如何进行平衡(LL , RR , LR , RL)
     */

    if (balanceFactor > 1 && getBalanceFactro_AVLTree(node->left) >= 0) { // RR
        node = sigleRotateWithRight(node);
    }

    if (balanceFactor < -1 && getBalanceFactro_AVLTree(node->right) <= 0) {//LL
        node = sigleRotateWithLeft(node);
    }

    if (balanceFactor > 1 && getBalanceFactro_AVLTree(node->left) < 0) { //LR
        node->left = sigleRotateWithLeft(node->left);
        node = sigleRotateWithRight(node);
    }

    if (balanceFactor < -1 && getBalanceFactro_AVLTree(node->right) > 0) {//RL
        node->right = sigleRotateWithRight(node->right);
        node = sigleRotateWithLeft(node);
    }

    return node;

}

void inOrder_AVLTree(AVLTree avlTree) {
    printf("中序遍历:  ");
    inOrder_AVLTree_static(avlTree->root);
}

static void inOrder_AVLTree_static(Node node) {

    if (node == NULL) {
        return;
    }

    inOrder_AVLTree_static(node->left);
    PRINTFKEY(node->key);
    inOrder_AVLTree_static(node->right);
}


void preOrder__AVLTree(AVLTree avlTree) {
    printf("前序遍历:  ");
    preOrder_AVLTree_static(avlTree->root);
}

static void preOrder_AVLTree_static(Node node) {
    if (node == NULL) {
        return;
    }
    PRINTFKEY(node->key);
    preOrder_AVLTree_static(node->left);
    preOrder_AVLTree_static(node->right);

}

void postOrder_AVLTree(AVLTree avlTree) {
    printf("后序遍历:  ");
    postOrder_AVLTree_static(avlTree->root);
}

static void postOrder_AVLTree_static(Node node) {

    if (node == NULL) {
        return;
    }

    postOrder_AVLTree_static(node->left);
    postOrder_AVLTree_static(node->right);
    PRINTFKEY(node->key);
}

bool contains_AVLTree(AVLTree avlTree, K key) {
    return contains_AVLTree_static(avlTree->root, key);
}

static bool contains_AVLTree_static(Node node, K key) {

    if (node == NULL) {
        return false;
    }

    if (compareTo(node->key, key) < 0) {
        return contains_AVLTree_static(node->right, key);
    } else if (compareTo(node->key, key) > 0) {
        return contains_AVLTree_static(node->left, key);
    } else {
        return true;
    }

}

Node minimum_AVLTree(AVLTree avlTree) {

    if (avlTree->size == 0) {
        return NULL;
    }

    return minimum_AVLTree_static(avlTree->root);
}

/**
 * 从以node为根节点的平衡二叉树中找到最小的节点。
 * @param node
 * @return
 */
static Node minimum_AVLTree_static(Node node) {

    if (node->left == NULL) {
        return node;
    }

    return minimum_AVLTree_static(node->left);
}

Node maximum_AVLTree(AVLTree avlTree) {

    if (avlTree->size == 0) {
        return NULL;
    }

    return maximum_AVLTree_static(avlTree->root);

}

static Node maximum_AVLTree_static(Node node) {

    if (node->right == NULL) {
        return node;
    }

    return maximum_AVLTree_static(node->right);

}


V get_AVLTree(AVLTree avlTree, K key) {

    if (avlTree->size == 0) {
        return INVALIDVALUE;
    }

    return get_AVLTree_static(avlTree->root, key);

}

static V get_AVLTree_static(Node node, K key) {

    if (node == NULL) {
        return INVALIDVALUE;
    }


    if (compareTo(node->key, key) < 0) {
        return get_AVLTree_static(node->right, key);
    } else if (compareTo(node->key, key) > 0) {
        return get_AVLTree_static(node->left, key);
    } else {
        return node->value;
    }
}


void set_AVLTree(AVLTree avlTree, K key, V val) {

    if (avlTree->size == 0) {
        return;
    }

    set_AVLTree_static(avlTree->root, key, val);

}

static void set_AVLTree_static(Node node, K key, V val) {

    if (node == NULL) {
        return;
    }

    if (compareTo(node->key, key) < 0) {
        set_AVLTree_static(node->right, key, val);
    } else if (compareTo(node->key, key) > 0) {
        set_AVLTree_static(node->left, key, val);
    } else {
        node->value = val;
    }

}

void remove_AVLTree(AVLTree avlTree, K key) {

    if (avlTree->size == 0) {
        return;
    }

    avlTree->root = remove_AVLTree_static(avlTree, avlTree->root, key);


}

static Node remove_AVLTree_static(AVLTree avlTree, Node node, K key) {

    if (node == NULL) {
        return NULL;
    }

    Node retNode;

    if (compareTo(node->key, key) < 0) {

        node->right = remove_AVLTree_static(avlTree, node->right, key);
        retNode = node;

    } else if (compareTo(node->key, key) > 0) {

        node->left = remove_AVLTree_static(avlTree, node->left, key);
        retNode = node;

    } else { //node节点就是要删除的节点

        Node delNode = node;
        if (node->left == NULL) { //node->left == NULL && (node->right == NULL||node->right!=NULL)

            avlTree->size--;
            retNode = delNode->right;
            FREE(delNode);

        } else if (node->right == NULL) { // node->right ==NULL&&node->left!=NULL
            avlTree->size--;
            retNode = delNode->left;
            FREE(delNode);

        } else { //node->right !=NULL&&node->left!=NULL

            Node miniNode = minimum_AVLTree_static(node->right);

            Node tempNode = MALLOC(struct Node, 1);
            tempNode->key = miniNode->key;
            tempNode->value = miniNode->value;
            tempNode->left = delNode->left;
            tempNode->right = delNode->right;

            tempNode->right = remove_AVLTree_static(avlTree, node->right, miniNode->key);
            FREE(delNode);
            retNode = tempNode;
        }
    }

    /**
     * 一个重要的边界问题 ， 当删除一个叶子节点时，retNode 会为空。
     *
     *                "一个重要的边界问题"
     */
    if (retNode == NULL) {
        return NULL;
    }

    //维护高度
    retNode->height = 1 + MAX(getHeight_AVLTree_static(retNode->left), getHeight_AVLTree_static(retNode->right));
    //计算平衡因子
    int balanceFactor = getBalanceFactro_AVLTree(retNode);


    if (balanceFactor > 1 && getBalanceFactro_AVLTree(retNode->left) >= 0) { // RR
        retNode = sigleRotateWithRight(retNode);
    }

    if (balanceFactor < -1 && getBalanceFactro_AVLTree(retNode->right) <= 0) {//LL
        retNode = sigleRotateWithLeft(retNode);
    }

    if (balanceFactor > 1 && getBalanceFactro_AVLTree(retNode->left) < 0) { //LR
        retNode->left = sigleRotateWithLeft(retNode->left);
        retNode = sigleRotateWithRight(retNode);
    }

    if (balanceFactor < -1 && getBalanceFactro_AVLTree(retNode->right) > 0) {//RL
        retNode->right = sigleRotateWithRight(retNode->right);
        retNode = sigleRotateWithLeft(retNode);
    }


    return retNode;

}



