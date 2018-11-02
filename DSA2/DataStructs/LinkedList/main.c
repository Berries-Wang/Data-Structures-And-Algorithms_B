//
// Created by wei on 9/28/18.
//
#include "LinkedList.h"
#include <stdio.h>


int main(int argc, char **argv) {

    PlinkedList list = initLinkedList();

    for (int i = 0; i < 8; ++i) {
        addFirst_LinkedList(list, i);

        show_LinkedList(list);

    }

    addLast_LinkedList(list, 9);
    show_LinkedList(list);
    printf(" 移除\n");
    for (int j = 0; j < 3; ++j) {
        removeFirst_LinkedList(list);
        show_LinkedList(list);
    }

    /*remove_LinkedList(list, 3);*/
    set_LinkedList(list, 3, 100);
    show_LinkedList(list);

    destory_LinkedList(list);

    return 0;
}

