//
// Created by wei on 9/22/18.
//
#include "Array.h"
#include <stdio.h>


int main(int argc, char **argv) {


    Array array = initArray(10);
    for (int i = 0; i < 15; i++) {
        addLast_Array(array, i);
    }

    show_Array(array);
    add_Array(array, 2, 66);
    add_Array(array, 3, 88);
    add_Array(array, 2, 99);

    addFirst_Array(array, 58);

    setEle_Array(array, 2, 33);

    bool con = contains_Array(array, 33);
    printf("是否包含：%d\n", con);
    printf("位置：%d\n", find_Array(array, 33));
    show_Array(array);

    remove_Array(array, 0);
    show_Array(array);
    remove_Array(array, array->size);
    show_Array(array);

    removeFirst_Array(array);
    show_Array(array);

    removeLast_Array(array);
    show_Array(array);

    removeEle_Array(array, 33);
    show_Array(array);

    for (int j = 0; j < 6; ++j) {
        removeLast_Array(array);
    }
    show_Array(array);


    return 0;
}

