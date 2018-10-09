//
// Created by wei on 9/20/18.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

private:

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        int lenl1 = this->getLength(l1);
        int lenl2 = this->getLength(l2);

        ListNode *ll1 = (lenl1 > lenl2 ? l1 : l2);
        ListNode *ll2 = (lenl1 > lenl2 ? l2 : l1);

        int temp = 0;
        int a, b, c;

        ListNode *pre = NULL;

        while (ll1 != NULL) {

            a = ll1->val;
            b = (ll2 == NULL ? 0 : ll2->val);

            c = a + b + temp;
            temp = c / 10;

            ll1->val = c % 10;
            pre = ll1;

            ll1 = ll1->next;
            ll2 = (ll2 == NULL ? NULL : ll2->next);

        }

        pre->next = (temp ? new ListNode(1) : NULL);

        return (lenl1 > lenl2 ? l1 : l2);

    }

private:
    int getLength(ListNode *root) {

        int length = 0;
        while (root != NULL) {
            length++;
            root = root->next;
        }

        return length;
    }
};

ListNode *createList(int *arr, int length) {

    ListNode *head = new ListNode(-1);
    ListNode *curNode = head;
    for (int i = 0; i < length; ++i) {

        ListNode *node = new ListNode(*(arr + i));
        curNode->next = node;
        curNode = node;

    }

    return head->next;

}

void show(ListNode *listNode) {
    while (listNode != NULL) {
        cout << listNode->val << "   ";
        listNode = listNode->next;
    }
    cout << endl;
}


int main(int argc, char **argv) {

    int l1[] = {5};
    int l2[] = {5};

    ListNode *ll1 = createList(l1, 1);
    ListNode *ll2 = createList(l2, 1);

    show(ll1);
    show(ll2);

    ListNode *res = (new Solution())->addTwoNumbers(ll1, ll2);
    show(res);

    return 0;
}

