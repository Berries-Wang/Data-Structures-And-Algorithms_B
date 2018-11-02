//
// Created by wei on 10/24/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

/**
 *
 * 超时
 *
 *
 */
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {

        this->target = target;
        int start = -1;

        vector<int> tempRes;
        helper(nums, tempRes, 0, start);
        return vector<vector<int> >(this->res.begin(), this->res.end());
    }

private:
    int target;
    set<vector<int> > res;

    void helper(vector<int> &nums, vector<int> tempRes, int sum, int start) {

        /*cout << "tempRes: ";
        for (int i = 0; i < tempRes.size(); ++i) {
            cout << tempRes[i] << "  ";
        }
        cout << endl;*/


        if (tempRes.size() == 4) {
            if (sum == this->target) {
                sort(tempRes.begin(), tempRes.end());
                this->res.insert(tempRes);

            }
            return;
        }
        int tempSum;
        for (int i = start + 1; i < nums.size(); ++i) {
            tempRes.push_back(nums[i]);
            tempSum = sum + nums[i];
            helper(nums, tempRes, tempSum, i);
            tempRes.pop_back();
        }
    }
};


int main(int argc, char **argv) {

    int array[] = {-463, -428, -392, -386, -348, -312, -280, -248, -247, -244, -224, -216, -198, -195, -195, -189, -175,
                   -173, -167, -155, -111, -96, -36, -28, -3, 10, 15, 22, 25, 44, 44, 49, 50, 68, 84, 88, 104, 107, 111,
                   116, 171, 208, 233, 304, 309, 313, 318, 323, 330, 331, 331, 358, 364, 365, 388, 396, 403, 425, 449};

    vector<int> test(array, array + sizeof(array) / sizeof(int));
    int target = 38;

    vector<vector<int> > res = (new Solution())->fourSum(test, target);

    for (int i = 0; i < res.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << "] " << endl;
    }

    cout << "size: " << res.size() << endl;

    return 0;
}
