//
// Created by wei on 9/27/18.
//

#include "LinkedList.h"
#include <stdio.h>


PlinkedList initLinkedList(void) {

    PlinkedList linkedList = MALLOC(LinkedList, 1);
    linkedList->size = 0;
    linkedList->dummyHead = MALLOC(Node, 1);
    linkedList->dummyHead->next = NULL;

    return linkedList;
}

void add_LinkedList(PlinkedList linkedList, int index, VALTYPE val) {

    if (index < 0 || index > linkedList->size) {
        fprintf(stderr, "add Error . index should be >=0 and <= size");
        return;
    }

    pNode pre = linkedList->dummyHead;

    for (int i = 0; i < index; i++) {
        pre = pre->next;
    }

    pNode addNode = MALLOC(Node, 1);
    addNode->data = val;
    addNode->next = pre->next;
    pre->next = addNode;
    linkedList->size++;
}

void addFirst_LinkedList(PlinkedList linkedList, VALTYPE val) {
    add_LinkedList(linkedList, 0, val);
}

void addLast_LinkedList(PlinkedList linkedList, VALTYPE val) {
    add_LinkedList(linkedList, linkedList->size, val);
}

bool contains_LinkedList(PlinkedList linkedList, VALTYPE val) {

    pNode curNode = linkedList->dummyHead->next;
    while (curNode != NULL) {
        if (curNode->data == val) {
            return true;
        }
        curNode = curNode->next;
    }
    return false;
}

VALTYPE get_LinkedList(PlinkedList linkedList, int index) {

    if (index < 0 || index >= linkedList->size) {
        fprintf(stderr, "select Error . index should be >=0 and <= size");
        return -1;
    }

    pNode curNode = linkedList->dummyHead;
    for (int i = 0; i < index; ++i) {
        curNode = curNode->next;
    }

    return curNode->data;

}

VALTYPE getFirst_LinkedList(PlinkedList linkedList) {
    return get_LinkedList(linkedList, 0);
}

VALTYPE getLast_LinkedList(PlinkedList linkedList) {
    return get_LinkedList(linkedList, linkedList->size - 1);
}


VALTYPE remove_LinkedList(PlinkedList linkedList, int index) {

    if (index < 0 || index >= linkedList->size) {
        fprintf(stderr, "remove Error . index should be >=0 and <= size");
        return -1;
    }

    pNode pre = linkedList->dummyHead;

    for (int i = 0; i < index; ++i) {
        pre = pre->next;
    }

    pNode delNode = pre->next;
    pre->next = delNode->next;
    delNode->next = NULL;
    VALTYPE res = delNode->data;
    FREE(delNode);

    return res;
}

VALTYPE removeFirst_LinkedList(PlinkedList linkedList) {
    return remove_LinkedList(linkedList, 0);
}

VALTYPE removeLast_LinkedList(PlinkedList linkedList) {
    return remove_LinkedList(linkedList, linkedList->size - 1);
}

void set_LinkedList(PlinkedList linkedList, int index, VALTYPE val) {

    if (index < 0 || index >= linkedList->size) {
        fprintf(stderr, "set Error . index should be >=0 and <= size");
        return;
    }

    pNode curNode = linkedList->dummyHead->next;
    for (int i = 0; i < index; ++i) {
        curNode = curNode->next;
    }
    curNode->data = val;

}

void show_LinkedList(PlinkedList linkList) {

    printf("LinkedList  Size:%d , head: ", linkList->size);
    pNode curNode = linkList->dummyHead->next;

    while (curNode != NULL) {
        PRINTF(curNode->data);
        curNode = curNode->next;
    }

    printf("NULL  Tail\n");
}

void destory_LinkedList(PlinkedList linkedList) {


    pNode curNode = linkedList->dummyHead;
    pNode delNode;

    while (curNode != NULL) {
        delNode = curNode;
        curNode = delNode->next;
        FREE(delNode);
    }

    FREE(linkedList);
    linkedList = NULL;

}
