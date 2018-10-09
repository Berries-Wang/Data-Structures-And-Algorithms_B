//
// Created by wei on 9/19/18.
//

#include "BST.h"


BST initBST_BST(void) {
    BST bst = MALLOC(struct BST);
    bst->size == 0;
    bst->root = NULL;

    return bst;
}

int size(BST bst) {

    return bst->size;

}

bool isEmpty(BST bst) {
    return bst->size == 0;
}

void add(BST bst, K key, V value) {

    bst->root = addNode(bst, bst->root, key, value);

}

static pNode addNode(BST bst, pNode node, K key, V value) {

    if (node == NULL) {

        pNode tempNode = MALLOC(Node);
        tempNode->key = key;
        tempNode->value = value;
        tempNode->left = tempNode->right = NULL;
        bst->size++;

        return tempNode;
    }

    if (compareTo(node->key, key) < 0) {
        node->right = addNode(bst, node->right, key, value);
    } else if (compareTo(node->key, key) > 0) {
        node->left = addNode(bst, node->left, key, value);
    } else {
        node->value = value;
    }

    return node;


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


bool contains(BST bst, K key) {
    return contains_static(bst->root, key);
}

static bool contains_static(pNode node, K key) {

    if (node == NULL) {
        return false;
    }

    if (compareTo(node->key, key) == 0) {
        return true;
    } else if (compareTo(node->key, key) > 0) {
        return contains_static(node->left, key);
    } else {
        return contains_static(node->right, key);
    }

}

void preOrder(BST bst) {
    printf("前序遍历：");
    preOrder_static(bst->root);
    printf("\n");
}

static void preOrder_static(pNode node) {

    if (node == NULL) {
        return;
    }

    PRINTF(node);
    preOrder_static(node->left);
    preOrder_static(node->right);

}


void inOrder(BST bst) {
    printf("中序遍历：");
    inOrder_static(bst->root);
    printf("\n");
}

static void inOrder_static(pNode node) {
    if (node == NULL) {
        return;
    }

    inOrder_static(node->left);
    PRINTF(node);
    inOrder_static(node->right);
}

//后序遍历二叉搜索树
void postOrder(BST bst) {
    printf("后序遍历：");
    postOrder_static(bst->root);
    printf("\n");
}

//后序遍历以node为根节点的二叉搜索树
static void postOrder_static(pNode node) {
    if (node == NULL) {
        return;
    }
    postOrder_static(node->left);
    postOrder_static(node->right);
    PRINTF(node);
}

void levelOrder(BST bst) {

}

pNode minimum(BST bst) {

    //二叉搜索树为空
    if (size(bst) == 0) {
        return NULL;
    }

    return minimum_static(bst->root);

}

static pNode minimum_static(pNode node) {

    if (node->left == NULL) {
        return node;
    }

    return minimum_static(node->left);

}

pNode maximum(BST bst) {

    if (isEmpty(bst)) {
        return NULL;
    }

    return maximum_static(bst->root);

}

static pNode maximum_static(pNode node) {

    if (node->right == NULL) {
        return node;
    }

    return maximum_static(node->right);

}


//删除最小值
VALUETYPE removeMin(BST bst) {

    pNode min = minimum(bst);

    if (min == NULL) {
        return NULLVALUE;
    }

    bst->root = removeMin_static(bst->root);
    bst->size--;

    VALUETYPE res = min->value;
    min = NULL;

    return res;

}

//删除以node为根节点的二叉搜索树中最小的节点。返回删除了最小节点之后的最小二叉搜索树
static pNode removeMin_static(pNode node) {

    if (node->left == NULL) {
        pNode right = node->right;
        node->right = NULL;
        FREE(node);

        return right;

    }

    node->left = removeMin_static(node->left);
    return node;

}


//删除最小值
VALUETYPE removeMax(BST bst) {

    pNode max = maximum(bst);

    if (max == NULL) {
        return NULLVALUE;
    }

    bst->root = removeMax_static(bst->root);
    bst->size--;

    VALUETYPE res = max->value;
    max = NULL;
    return res;

}

//删除以node为根节点的二叉搜索树中最小的节点。返回删除了最小节点之后的最小二叉搜索树
static pNode removeMax_static(pNode node) {

    if (node->right == NULL) {
        pNode left = node->left;
        node->left = NULL;
        FREE(node);

        return left;
    }

    node->right = removeMax_static(node->right);
    return node;

}

void removeNode(BST bst, K key) {

    bst->root = removeNode_static(bst, bst->root, key);

}

static pNode removeNode_static(BST bst, pNode node, K key) {

    if (node == NULL) {
        return NULL;
    }

    if (compareTo(node->key, key) > 0) {
        node->left = removeNode_static(bst, node->left, key);
        return node;
    } else if (compareTo(node->key, key) < 0) {
        node->right = removeNode_static(bst, node->right, key);
        return node;
    } else { //node->value == val    node是要删除的节点

        if (node->left == NULL) { //node->left == NULL && (node->right == NULL||node->right!=NULL)
            pNode right = node->right;
            node->right = NULL;
            bst->size--;
            FREE(node);
            return right;
        }

        if (node->right == NULL) {  // node->right ==NULL&&node->left!=NULL
            pNode left = node->left;
            node->left = NULL;
            bst->size--;
            FREE(node);
            return left;
        }

        //node->right !=NULL&&node->left!=NULL

        pNode successor = minimum_static(node->right);

        /**
         * 在删除最小元素时，会释放掉最小元素的内存，这里需要保存最小元素的值，防止出现非法内存访问
         */
        pNode tempNode = MALLOC(Node);
        /**
         * 进行深度复制
         */
        tempNode->value = successor->value;
        tempNode->key = successor->key;
        tempNode->right = successor->right;
        tempNode->left = successor->left;

        node->right = removeMin_static(node->right);


        tempNode->right = node->right;
        tempNode->left = node->left;
        FREE(node);

        return tempNode;

    }

}

V get_BST(BST bst, K key) {

    return get_BST_static(bst->root, key);

}

static V get_BST_static(pNode node, K key) {

    if (node == NULL) {
        return NULLVALUE;
    }

    if (compare(node->key, key) > 0) {
        return get_BST_static(node->left, key);
    } else if (compare(node->key, key) < 0) {
        return get_BST_static(node->right, key);
    } else {
        return node->value;
    }

}


void set_BST(BST bst, K key, V val) {
    set_BST_static(bst->root, key, val);
}

static void set_BST_static(pNode node, K key, V val) {
    if (node == NULL) {
        return;
    }

    if (compare(node->key, key) > 0) {
        set_BST_static(node->left, key, val);
    } else if (compare(node->key, key) < 0) {
        set_BST_static(node->right, key, val);
    } else {
        node->value = val;
    }
}








