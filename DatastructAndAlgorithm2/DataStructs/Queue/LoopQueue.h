//
// Created by wei on 9/27/18.
//

/**
 *
 * 循环队列： 有意识地空出一个位置
 *     队列为空： tail == front
 *     队列为满:  (tail+1)%(capacity+1) == front
 *
 *     注意：这里的capacity没有包括那个有意识地空出的位置
 *
 *
 */

#ifndef LOOPQUEUE_H_
#define LOOPQUEUE_H_

#include <stdlib.h>
#include <stdbool.h>

#define ELETYPE int
#define  MALLOC(type, counts)   ((type*)malloc(sizeof(type) * counts))
#define  FREE(headPointer)  (free((headPointer)))
#define  ISFULL(queue)  ((queue->tail+1) %(queue->capacity+1) == queue->front)
#define  PRINTF(val)   (printf("%-3d",val))


typedef struct LoopQueue *Queue;

struct LoopQueue {
    //数组,存放数据
    ELETYPE *data;
    //队列容量 , 不包括那个有意识地空出的位置
    int capacity;
    //当前元素个数
    int size;
    //指向队列首部(第一个有元素的位置)  "变量的定义很重要"
    int front;
    //指向队列尾(队尾元素的下一个位置，入队时存放数据的地方)  "变量的定义很重要"
    int tail;
};

/**
 * 初始化一个循环队列
 * @param capacity 队列的容量
 * @return  指向 struct LoopQueue 类型的指针
 */
Queue initQueue_Loop(int capacity);

/**
 * 获取循环队列中元素个数
 *
 * @param queue 被操作的循环队列
 * @return  元素数
 */
int getSize_LoopQueue(Queue queue);

/**
 * 判断队列是否为空
 * @param queue 被操作的循环队列
 * @return  是否为空
 */
bool isEmpty_LoopQueue(Queue queue);

/**
 * 入队
 * @param queue
 * @param val
 */
void enqueue_LoopQueue(Queue queue, ELETYPE val);

/**
 * 出队
 * @param queue
 * @return
 */
ELETYPE deQueue_LoopQueue(Queue queue);

/**
 * 获取队首元素
 * @param queue
 * @return
 */
ELETYPE getFront_LoopQueue(Queue queue);

/**
 * 对循环队列进行扩容
 * @param queue
 * @param newCapacity
 */
static void reSize_LoopQueue(Queue queue, int newCapacity);

/**
 * 打印队列里面的元素
 * @param queue
 */
void show_LoopQueue(Queue queue);

/**
 * 销毁队列
 * @param queue
 */
void destory_LoopQueue(Queue queue);

#endif //LOOPQUEUE_H_
