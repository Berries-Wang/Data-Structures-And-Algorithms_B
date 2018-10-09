//
// Created by wei on 9/20/18.
//

#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

private:
    queue<int> q;
    ListNode *res;


public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        ListNode *ll1 = l1;
        ListNode *ll2 = l2;

        this->res = new ListNode(0);


        ListNode *curNode;
        curNode = this->res;

        while (ll1 != NULL && ll2 != NULL) {


            int sum;
            if (!this->q.empty()) {
                sum = ll1->val + ll2->val + this->q.front();
                this->q.pop();
            } else {
                sum = ll1->val + ll2->val;
            }

            if (sum >= 10) {
                this->q.push(1);
            }

            ListNode *node = new ListNode(sum % 10);
            curNode->next = node;
            curNode = node;

            ll1 = ll1->next;
            ll2 = ll2->next;


        }


        ListNode *ll3 = NULL;
        if (ll1 != NULL) {
            ll3 = ll1;
        } else if (ll2 != NULL) {
            ll3 = ll2;
        }


        while (ll3 != NULL || !this->q.empty()) {
            if (this->q.empty() && ll3 != NULL) {
                curNode->next = ll3;
                break;
            } else if (ll3 != NULL && !this->q.empty()) {

                int sum = ll3->val + this->q.front();
                this->q.pop();

                if (sum >= 10) {
                    this->q.push(1);
                }

                ListNode *node = new ListNode(sum % 10);
                curNode->next = node;
                curNode = node;

                ll3 = ll3->next;


            } else if (ll3 == NULL && !this->q.empty()) {
                curNode->next = new ListNode(this->q.front());
                this->q.pop();
            }
        }

        return this->res->next;

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

