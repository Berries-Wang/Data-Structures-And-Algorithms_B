//
// Created by wei on 10/12/18.
//
#include <iostream>
#include <vector>


/**
 *
 * 双指针解法
 *
 * Time complexity:O(n)
 * space  complexity:O(1)
 *
 *
 */
using namespace std;


class Solution {
public:
    int maxArea(vector<int> &height) {

        int maxArea = 0;
        int left = 0;
        int right = static_cast<int>(height.size() - 1);
        int curArea;

        while (left < right) {

            curArea = minimum(height[left], height[right]) * (right - left);
            maxArea = maxArea > curArea ? maxArea : curArea;

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }

        }

        return maxArea;
    }

private:
    int minimum(int e1, int e2) {
        return e1 > e2 ? e2 : e1;
    }

};


int main(int argc, char **argv) {
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    vector<int> test(arr, arr + sizeof(arr) / sizeof(int));

    cout << (new Solution)->maxArea(test) << endl;

    return 0;
}


