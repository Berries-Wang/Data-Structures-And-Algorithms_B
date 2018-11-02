//
// Created by wei on 9/28/18.
//

#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int symbol;
        //将x转为正整数
        if (x > 0) {
            symbol = 1;
        } else {
            symbol = -1;
            x = x * symbol;
        }

        int temp = 0, res = 0;

        while (x > 0) {
            temp = x % 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && temp > 7)) {
                return 0;
            }
            res = res * 10 + temp;
            x = x / 10;
        }

        return res * symbol;

    }
};


int main(int argc, char **argv) {

    long test = -2147483648;
    cout << test << "  反转后:  " << Solution().reverse(test) << endl;

    return 0;
}