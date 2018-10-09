//
// Created by wei on 9/30/18.
//

#include "BSTMap.h"

int main(int argc, char **argv) {

    char *strs[7] = {"E", "C", "H", "B", "D", "G", "I"};

    /* BST bst = initBST_BST();

     for (int i = 0; i < 7; ++i) {
         add(bst, strs[i], i);
     }
     preOrder(bst);

     add(bst, "K", 99);
     preOrder(bst);

     inOrder(bst);

     printf("-----------------------------------------\n");

     V val = get_BST(bst, "D");
     printf("%s : %d\n", "D", val);

     set_BST(bst, "D", 88);


     val = get_BST(bst, "D");
     printf("%s : %d\n", "D", val);

     printf("size: %d\n", bst->size);


     preOrder(bst);*/

    Map map = initMap_BSTMap();

    for (int i = 0; i < 7; ++i) {
        add_BSTMap(map, strs[i], i + 1);
    }
    set_BSTMap(map, strs[2], 1000);
    printf("%d\n", get_BSTMap(map, strs[2]));
    return 0;
}

