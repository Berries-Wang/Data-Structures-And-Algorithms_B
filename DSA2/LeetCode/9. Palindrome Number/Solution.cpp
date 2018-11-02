//
// Created by wei on 9/29/18.
//

#include <iostream>


using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) {
            return false;
        }

        string str = to_string(x);

        for (int i = 0, len = str.length(); i < len / 2; ++i) {

            if (str[i] != str[len - i - 1]) {
                return false;
            }

        }
        return true;

    }
};

int main(int argc, char **argv) {

    int test = -121;
    bool res = Solution().isPalindrome(test);

    if (res) {
        cout << test << "是回文数" << endl;
    } else {
        cout << test << "不是回文数" << endl;
    }

    return 0;
}