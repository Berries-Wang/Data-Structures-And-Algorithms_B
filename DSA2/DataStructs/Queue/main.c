//
// Created by wei on 9/27/18.
//
#include <stdio.h>
#include "LoopQueue.h"


int main(int argc, char **argv) {

    Queue queue = initQueue_Loop(10);

    for (int i = 1; i < 30; ++i) {

        if (i % 3 == 0) {
            deQueue_LoopQueue(queue);
        }
        enqueue_LoopQueue(queue, i);
        show_LoopQueue(queue);
    }

    for (int j = 0; j < 15; ++j) {
        deQueue_LoopQueue(queue);
        show_LoopQueue(queue);
    }

    destory_LoopQueue(queue);

    return 0;
}

