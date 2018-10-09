//
// Created by wei on 9/19/18.
//

#include "BST.h"

int main(int argc, char **argv) {

    int arr[] = {5, 3, 6, 8, 4, 2};
    BST bst = MALLOC(struct BST);
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
        add(bst, arr[i]);
    }

    preOrder(bst);
    inOrder(bst);
    postOrder(bst);
    printf("Hello World C\n");

    /*pNode min = minimum(bst);
    printf("最小值: %d\n", min->value);

    pNode max = maximum(bst);
    printf("最大值: %d\n", max->value);

    printf("--------------------------------------\n");
    // int a = removeMin(bst);
    int a = removeMax(bst);
    printf("删除的值: %d\n", a);
    preOrder(bst);*/

    removeNode(bst, 6);
    printf("size: %d\n", bst->size);
    preOrder(bst);
    return 0;
}

