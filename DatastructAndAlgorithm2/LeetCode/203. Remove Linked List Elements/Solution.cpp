//
// Created by wei on 9/28/18.
//

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {

        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;

        ListNode *curNode = dummyNode;

        while (curNode->next != NULL) {

            if (curNode->next->val == val) {
                curNode->next = curNode->next->next;
            } else{
                curNode = curNode->next;
            }
        }
        return dummyNode->next;

    }
};


int main(int argc, char **argv) {


    return 0;
}
