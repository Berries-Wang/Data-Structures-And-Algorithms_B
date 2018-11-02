//
// Created by wei on 9/25/18.
//

#ifndef DSA2_STACK_H
#define DSA2_STACK_H

#include "../Array/Array.h"

typedef struct Stack *Stack;

struct Stack {

    Array data;

};


/**
 * 初始化栈
 */
Stack initStack(int);

/**
 * 入栈
 */
void push_Stack(Stack, VALUETYPE);

/**
 * 出栈
 */
void pop_Stack(Stack);

/**
 * 查看栈顶元素
 */
VALUETYPE peek_Stack(Stack);

/**
 * 获取栈东元素数量
 */
int size_Stack(Stack);

/**
 * 查看栈是否为空
 */
bool isEmpty_Stack(Stack);

/**
 * 打印栈
 */
void show_Stack(Stack);


#endif //DSA2_STACK_H
