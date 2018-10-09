#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <time.h>


using namespace std;

/**
 *
 * 回溯法(不是最优解)
 *
 *  递归调用的一个重要特征---要返回（回溯）
 *
 *  转换问题
 *  将此问题转换为树形问题
class Solution {

private:
    map<vector<int>, bool> result;
    vector<vector<int>> result1;

public:
    vector<vector<int>> threeSum(vector<int> &nums) {

        vector<int> res(0);

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << ",";
        }
        cout << endl;


        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) {
            this->helper(nums, res, i, 0);
        }

        map<vector<int>, bool>::iterator it;
        for (it = this->result.begin(); it != this->result.end(); it++) {
            result1.push_back(it->first);
        }
        return this->result1;

    }

private:
    void helper(vector<int> &nums, vector<int> res, int curIndex, int sum) {

        res.push_back(nums[curIndex]);
        sum += nums[curIndex];
        curIndex += 1;


        if (res.size() == 3) {
            if (sum == 0) {
                std::sort(res.begin(), res.end());
                this->result[res] = true;
            }

            cout << "sum: " << sum << "   ";
             for (int i = 0; i < res.size(); i++) {
                 cout << res[i] << ",";
             }
             cout << endl;
            return;
        }

        for (int i = curIndex; i < nums.size(); ++i) {
            this->helper(nums, res, i, sum);
        }

    }
};*/



/**
 *
 * 最优解:O(n^2)
 *  动态规划？？？（去掉重复子问题，寻找最优子问题）
 * 先从集合中选出一个数，再在集合剩余的元素中利用指针对撞来求解
 *
 *
 */
class Solution {

private:
    vector<vector<int>> result;

public:
    vector<vector<int>> threeSum(vector<int> &nums) {

        if (nums.size() <= 2) {
            return this->result;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {

            int a = nums[i];
            if (a > 0) {
                break;
            }
            if (i > 0 && a == nums[i - 1]) { //避免重复元素
                continue;
            }
            for (int j = i + 1, k = nums.size() - 1; j < k;) {

                int b = nums[j];
                int c = nums[k];

                int value = a + b + c;

                if (value == 0) {
                    this->result.push_back(vector<int>({a, b, c}));
                    while (b == nums[++j]);  // 跳过重复出现的元素
                    while (c == nums[--k]);  // 跳过重复出现的元素
                } else if (value > 0) {
                    k--;
                } else {
                    j++;
                }

            }


        }

        return this->result;

    }
};


int main(int argc, char **argv) {

    /*  int nums[] = {-1, 0, 1, 2, -1, -4};
int nums[] = {0, 0, 0};*/

    int nums[] = {-15, 6, 7, 0, -14, -5, -3, -10, -14, 1, -14, -1, -11, -11, -15, -1, 3, -12, 7, 14, 1, 6, -6, 7, 1, 1,
                  0, -4, 8, 7, 2, 1, -2, -6, -14, -9, -3, -1, -12, -2, 7, 11, 4, 12, -14, -4, -4, 4, -1, 10, 3, -14, 1,
                  12, 0, 10, -9, 8, -9, 14, -8, 8, 0, -3, 10, -6, 4, -8, 0, -1, -3, -8, -4, 8, 11, -3, -11, -8, 8, 3,
                  10, -3, -4, -4, -14, 12, 13, -8, -3, 12, -8, 4, 5, -1, -14, -8, 8, -3, -9, -15, 12, -5, -7, -15, -12,
                  11, -11, 14, 11, 12, 3, 6, -6};
    vector<int> arr(nums, nums + sizeof(nums) / sizeof(int));


    clock_t start = clock();
    vector<vector<int>> result = (new Solution())->threeSum(arr);
    clock_t end = clock();
    cout << "执行时间 : " << ((static_cast <double> (end))
                          - start) / CLOCKS_PER_SEC << "s" << endl;

    cout << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}