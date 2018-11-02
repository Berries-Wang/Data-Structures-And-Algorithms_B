//
// Created by wei on 9/27/18.
//
#include "LoopQueue.h"
#include <stdio.h>

Queue initQueue_Loop(int capacity) {

    Queue queue = MALLOC(struct LoopQueue, 1);
    queue->size = 0;
    queue->front = queue->tail = 0;
    queue->capacity = capacity;
    queue->data = MALLOC(int, capacity + 1);

    return queue;

}

int getSize_LoopQueue(Queue queue) {

    return queue->size;

}

bool isEmpty_LoopQueue(Queue queue) {

    return queue->tail == queue->front;

}

void enqueue_LoopQueue(Queue queue, ELETYPE val) {

    queue->data[queue->tail] = val;
    queue->size++;
    queue->tail = (queue->tail + 1) % (queue->capacity + 1);

    if (ISFULL(queue)) {
        reSize_LoopQueue(queue, queue->capacity * 2);
    }

}


static void reSize_LoopQueue(Queue queue, int newCapacity) {

    ELETYPE *data = MALLOC(ELETYPE, newCapacity + 1);

    for (int i = 0; i < queue->size; ++i) {
        int curIndex = (queue->front + i) % (queue->capacity + 1);
        data[i] = queue->data[curIndex];

    }

    FREE(queue->data);
    queue->data = data;
    queue->capacity = newCapacity;
    queue->front = 0;
    queue->tail = queue->size;

}

ELETYPE deQueue_LoopQueue(Queue queue) {

    if (isEmpty_LoopQueue(queue)) {
        fprintf(stderr, "The Queue is Empty");
        return -1;
    }

    queue->size--;
    ELETYPE re = queue->data[queue->front];
    queue->front = (queue->front + 1) % (queue->capacity + 1);

    if (queue->size == queue->capacity / 4 && queue->capacity / 2 != 0) {
        reSize_LoopQueue(queue, queue->capacity / 2);
    }

    return re;

}

ELETYPE getFront_LoopQueue(Queue queue) {

    if (isEmpty_LoopQueue(queue)) {
        fprintf(stderr, "The Queue is Empty");
        return -1;
    }

    return queue->data[queue->front];

}

void show_LoopQueue(Queue queue) {

    printf("LoopQueue(size,capacity) (%d,%d) front[ ", queue->size, queue->capacity);
    int curIndex = queue->front;
    for (int i = 0; i < queue->size; i++) {

        PRINTF(queue->data[curIndex]);
        if (i < queue->size - 1) {
            printf(" , ");
        }
        curIndex = (curIndex + 1) % (queue->capacity + 1);
    }
    printf("] tail\n");
}

void destory_LoopQueue(Queue queue) {

    FREE(queue->data);
    queue->data = NULL;
    FREE(queue);
    queue = NULL;

}


