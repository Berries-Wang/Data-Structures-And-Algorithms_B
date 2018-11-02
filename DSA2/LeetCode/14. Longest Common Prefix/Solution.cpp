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

        int tem = 0;
        int start = match(strs[1], strs[0], min(strs[1].length(), strs[0].length()));

        if (start == 0) {
            return "";
        }

        for (int i = 2; i < strs.size(); ++i) {

            tem = match(strs[i], strs[0], start);

            if (tem < start) {
                start = tem;
            }

            if (start == 0) {
                return "";
            }

        }

        return string(strs[0].begin(), strs[0].begin() + start);

    }

private:
    int match(const string &s1, const string &s2, int length) {

        if (s1.length() == 0) {
            return 0;
        }

        int i;
        for (i = 0; i < length; ++i) {
            if (s1[i] != s2[i]) {
                break;
            }
        }
        return i;
    }
};


int main(int argc, char **argv) {

    //string ss[] = {"flower", "flow", "flight"};
    string ss[] = {"dog", "racecar", "car"};
    vector<string> test;
    for (int j = 0; j < sizeof(ss) / sizeof(string); ++j) {
        test.push_back(ss[j]);
    }

    cout << (new Solution())->longestCommonPrefix(test) << endl;


    return 0;
}