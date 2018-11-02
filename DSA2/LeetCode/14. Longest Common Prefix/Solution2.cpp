//
// Created by wei on 10/15/18.
//

#include <iostream>
#include <vector>
#include <string>


using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {

        if (strs.size() == 0) {
            return "";
        } else if (strs.size() == 1) {
            return strs[0];
        }

        int length = 0;
        bool flag = true;

        while (flag) {

            for (int i = 1; i < strs.size(); ++i) {

                if (strs[i][length] != strs[0][length]) {
                    flag = false;
                    break;
                }
            }

            length++;
        }

        if (length == 1) {
            return "";
        } else {
            return strs[0].substr(0, length - 1);
        }

    }
};


int main(int argc, char **argv) {

    string ss[] = {"flower", "flow", "flight"};
    //string ss[] = {"dog", "racecar", "car"};
    vector<string> test;
    for (int j = 0; j < sizeof(ss) / sizeof(string); ++j) {
        test.push_back(ss[j]);
    }

    cout << (new Solution())->longestCommonPrefix(test) << endl;


    return 0;
}