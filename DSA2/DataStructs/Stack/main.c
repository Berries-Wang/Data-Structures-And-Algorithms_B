//
// Created by wei on 9/25/18.
//

#include "Stack.h"
#include <stdio.h>


int main(int argc, char **argv) {

    Stack stack = initStack(10);

    for (int i = 0; i < 6; ++i) {
        push_Stack(stack, i);
    }

    show_Stack(stack);

    pop_Stack(stack);
    show_Stack(stack);


    return 0;
}
