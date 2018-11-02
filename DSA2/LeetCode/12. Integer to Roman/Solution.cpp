//
// Created by wei on 10/14/18.
//

#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {

        int temp;
        int index = 0;
        int curDigits;

        string romams[4][10] = {
                {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                {"", "M", "MM", "MMM"}
        };


        string res = "";

        int k[4] = {0};

        for (int i = 0; i < 4; ++i) {
            k[3 - i] = num % 10;
            num = num / 10;
        }
        for (int j = 0; j < 4; ++j) {
            res += romams[3 - j][k[j]];
        }
        return res;
    }
};


int main(int argc, char **argv) {

    int test = 1994;

    cout << test << "翻转后: " << (new Solution())->intToRoman(test) << endl;

    return 0;
}