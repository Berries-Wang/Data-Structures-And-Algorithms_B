//
// Created by wei on 9/27/18.
//

/**
 *
 * 链表计数从0开始
 *
 *
 */

#ifndef DSA2_LINKLIST_H
#define DSA2_LINKLIST_H


#include <stdbool.h>
#include <stdlib.h>

#define  VALTYPE int

typedef struct Node Node;
typedef struct Node *pNode;

typedef struct LinkedList LinkedList;
typedef struct LinkedList *PlinkedList;

#define  MALLOC(type, count) ((type*)malloc(sizeof(type)*count))
#define  FREE(pHead)   (free(pHead))
#define  PRINTF(val)   (printf("%3d-->",val))


//节点定义
struct Node {

    //节点值
    VALTYPE data;
    //当前节点的下一个节点
    pNode next;

};

//链表定义
struct LinkedList {

    //链表的虚拟头节点(不存放任何值)
    pNode dummyHead;
    //链表的节点数目
    int size;

};

/**
 * 初始化一个链表
 * @return
 */
PlinkedList initLinkedList(void);

/**
 * 先链表中的任意位置添加节点
 * @param index
 * @param val
 */
void add_LinkedList(PlinkedList linkedList, int index, VALTYPE val);

/**
 * 向链表的第一个位置添加节点
 * @param val
 */
void addFirst_LinkedList(PlinkedList linkedList, VALTYPE val);

/**
 * 向链表的最后一个位置添加节点
 * @param val
 */
void addLast_LinkedList(PlinkedList linkedList, VALTYPE val);

/**
 * 链表中是否包含指定节点
 * @param val 
 * @return 
 */
bool contains_LinkedList(PlinkedList linkedList, VALTYPE val);

/**
 * 获取对应位置上的节点的值
 * @param index
 * @return
 */
VALTYPE get_LinkedList(PlinkedList linkedList, int index);
/**
 * 获取第一个位置上的节点的值
 * @param index
 * @return
 */
VALTYPE getFirst_LinkedList(PlinkedList linkedList);

/**
 * 获取最后一个位置上的节点的值
 * @param index
 * @return
 */
VALTYPE getLast_LinkedList(PlinkedList linkedList);

/**
 * 移除链表中指定位置上的节点
 * @param index
 * @return  被移除的节点的值
 */
VALTYPE remove_LinkedList(PlinkedList linkedList, int index);

/**
 * 移除链表中第一个位置上的节点
 * @param index
 * @return  被移除的节点的值
 */
VALTYPE removeFirst_LinkedList(PlinkedList linkedList);

/**
 * 移除链表中最后一个位置上的节点
 * @param index
 * @return  被移除的节点的值
 */
VALTYPE removeLast_LinkedList(PlinkedList linkedList);

/**
 * 给链表上的指定位置上的节点设置值
 * @param index
 * @param val
 */
void set_LinkedList(PlinkedList linkedList, int index, VALTYPE val);


/**
 * 打印链表
 */
void show_LinkedList(PlinkedList linkList);

/**
 * 销毁链表
 * @param linkedList
 */
void destory_LinkedList(PlinkedList linkedList);

#endif //DSA2_LINKLIST_H
