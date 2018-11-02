//
// Created by wei on 10/12/18.
//
#include <iostream>
#include <vector>

/**
 *
 * 暴力解法
 *
 * Time complexity:O(n^2)
 * space  complexity:O(1)
 */

using namespace std;


class Solution {
public:
    int maxArea(vector<int> &height) {

        unsigned long size = height.size();
        int maxArea = 0;

        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; j++) {

                int min = this->minimum(height[i], height[j]);
                int area = min * (j - i);

                maxArea = maxArea > area ? maxArea : area;

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

    /* for (int i = 0; i < test.size(); ++i) {
         cout << test[i] << "  ";
     }*/
    cout << (new Solution)->maxArea(test) << endl;

    return 0;
}


