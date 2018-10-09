//
// Created by wei on 9/25/18.
//

#include <stdio.h>
#include "Stack.h"

Stack initStack(int capacity) {

    Stack stack = MALLOC(struct Stack, 1);
    stack->data = initArray(capacity);

    return stack;

}

void push_Stack(Stack stack, VALUETYPE val) {

    addLast_Array(stack->data, val);

}

void pop_Stack(Stack stack) {

    removeLast_Array(stack->data);

}

VALUETYPE peek_Stack(Stack stack) {
    return getEle_Array(stack->data, stack->data->size - 1);
}

int size_Stack(Stack stack) {
    return stack->data->size;
}

bool isEmpty_Stack(Stack stack) {
    return stack->data->size == 0;
}

void show_Stack(Stack stack) {

    printf("Stack  Boom[");
    for (int i = 0; i < stack->data->size; ++i) {

        PRINTF(stack->data->data[i]);

        if (i == stack->data->size - 1) {
            printf("] top");
        } else {
            printf(",");
        }
    }

    printf("\n");

}