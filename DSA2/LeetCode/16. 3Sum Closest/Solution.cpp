//
// Created by wei on 10/15/18.
//

/**
 *
 * 双指针（指针对撞）
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {

        sort(nums.begin(), nums.end());//排序

        int size_nums = nums.size();
        int sum = 0;
        int offset = INT32_MAX; //三数之和与target的偏移量

        for (int i = 0; i < size_nums - 2; ++i) {

            int l = i + 1;
            int r = size_nums - 1;

            while (l < r) {

                int tempSum = nums[i] + nums[l] + nums[r];
                int tempOffset = abs(tempSum - target);

                if (tempOffset < offset) {
                    sum = tempSum;
                    offset = tempOffset;
                }

                if (tempSum < target) { //注意，着这里是用tempSum来判断
                    l++;
                } else if (tempSum > target) {
                    r--;
                } else {
                    return target;
                }
            }
        }
        return sum;

    }
};

int main(int argc, char **argv) {

    int array[] = {1, 2, 4, 8, 16, 32, 64, 128};
    int target = 82;
    vector<int> test(array, array + sizeof(array) / sizeof(int));


    cout << (new Solution())->threeSumClosest(test, target) << endl;


    return 0;
}
