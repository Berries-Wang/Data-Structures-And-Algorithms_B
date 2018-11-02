#include <iostream>

using namespace std;


/*
 * LeetCode 112
 *
 * 回溯法
 * */

/**
 * Definition for a binary tree node.
 *
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

private:

public:
    bool hasPathSum(TreeNode *root, int sum) {
        return this->calcPath(root, 0, sum);
    }

    bool calcPath(TreeNode *node, int cursum, const int &sum) {

        if (node == NULL) {
            return false;
        }

        cursum += node->val;
        if (cursum == sum && node->left == NULL && node->right == NULL) {
            return true;
        }


        return this->calcPath(node->left, cursum, sum) ||
               this->calcPath(node->right, cursum, sum);

    }
};


int main() {

    for (int i = 0; i < 20; ++i) {

        std::cout << "Hello, World!" << std::endl;

    }
    return 0;
}