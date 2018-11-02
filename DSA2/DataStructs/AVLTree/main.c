//
// Created by wei on 10/8/18.
//

#include <stdio.h>
#include "AVLTree.h"


int main(int argc, char **argv) {

    char *strs[] = {"A", "B", "C", "D", "E", "F", "G"};

    // printf("%lu\n", sizeof(strs) / sizeof(char *)); 15

    AVLTree avlTree = initAVLTree();

    for (int i = 0; i < sizeof(strs) / sizeof(char *); ++i) {
        /*printf("%s  ", strs[i]);*/
        add_AVLTree(avlTree, strs[i], i);
    }

    printf("\n");

    inOrder_AVLTree(avlTree);
    printf("\n");
    preOrder__AVLTree(avlTree);
    printf("\n");
    postOrder_AVLTree(avlTree);
    printf("\n");
    printf("是否包含\"A\": %d", contains_AVLTree(avlTree, "A"));
    printf("\n");
    printf("最小的字符串:");

    Node minNode = minimum_AVLTree(avlTree);
    if (minNode == NULL) {
        printf("不存在");
    } else {
        printf("%s\n", minNode->key);
    }

    printf("\n");
    printf("最大的字符串:");
    Node maxNode = maximum_AVLTree(avlTree);
    if (maxNode == NULL) {
        printf("不存在");
    } else {
        printf("%s\n", maxNode->key);
    }
    printf("\n");
    printf("键为G的值：");
    V val = get_AVLTree(avlTree, "G");
    printf("%d", val);
    printf("\n");

    set_AVLTree(avlTree, "G", 999);

    printf("\n");
    printf("键为G的值：");
    val = get_AVLTree(avlTree, "G");
    printf("%d", val);
    printf("\n");


    remove_AVLTree(avlTree, "D");

    printf("\n");
    preOrder__AVLTree(avlTree);

    return 0;
}