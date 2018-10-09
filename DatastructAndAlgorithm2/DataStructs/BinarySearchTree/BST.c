//
// Created by wei on 9/19/18.
//

#include "BST.h"


int size(BST bst) {

    return bst->size;

}

bool isEmpty(BST bst) {
    return bst->size == 0;
}

void add(BST bst, VALUETYPE value) {

    bst->root = addNode(bst, bst->root, value);

}

static pNode addNode(BST bst, pNode node, VALUETYPE value) {

    if (node == NULL) {

        pNode tempNode = MALLOC(Node);
        tempNode->value = value;
        tempNode->left = tempNode->right = NULL;
        bst->size++;

        return tempNode;
    }

    if (compareTo(node->value, value) < 0) {
        node->right = addNode(bst, node->right, value);
    } else if (compareTo(node->value, value) > 0) {
        node->left = addNode(bst, node->left, value);
    }

    return node;


}

static int compareTo(VALUETYPE v1, VALUETYPE v2) {
    if (v1 > v2) {
        return 1;
    } else if (v1 < v2) {
        return -1;
    } else {
        return 0;
    }
}


bool contains(BST bst, VALUETYPE value) {
    return contains_static(bst->root, value);
}

static bool contains_static(pNode node, VALUETYPE value) {

    if (node == NULL) {
        return false;
    }

    if (compareTo(node->value, value) == 0) {
        return true;
    } else if (compareTo(node->value, value) > 0) {
        return contains_static(node->left, value);
    } else {
        return contains_static(node->right, value);
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

void removeNode(BST bst, VALUETYPE val) {

    bst->root = removeNode_static(bst, bst->root, val);

}

static pNode removeNode_static(BST bst, pNode node, VALUETYPE val) {

    if (node == NULL) {
        return NULL;
    }

    if (compareTo(node->value, val) > 0) {
        node->left = removeNode_static(bst, node->left, val);
        return node;
    } else if (compareTo(node->value, val) < 0) {
        node->right = removeNode_static(bst, node->right, val);
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
        tempNode->right = successor->right;
        tempNode->left = successor->left;

        node->right = removeMin_static(node->right);


        tempNode->right = node->right;
        tempNode->left = node->left;
        FREE(node);

        return tempNode;

    }

}








