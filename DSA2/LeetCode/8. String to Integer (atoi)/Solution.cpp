//
// Created by wei on 9/28/18.
//

#include <iostream>


/**
 *
 * 明确变量的定义:
 *       len:字符串长度
 *       start：当前正在判定的字符的索引
 *       symbol：是正整数还是负整数
 *       res：转换的结果
 *
 *
 *
 * 以及如何判定整数溢出
 *
 */


/*
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;   如何判定整数溢出
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;    如何判定整数溢出
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

 */
using namespace std;

class Solution {
public:
    int myAtoi(string str) {

        int len = str.length();
        int start = -1;
        int symbol = 1;
        int res = 0;


        if (len == 0) {
            return 0;
        }
        /**
         *  去除前面的空白字符
         *
         * 迭代完之后start的索引是第一个不为空白字符的索引
         *
         */
        while (start + 1 < len && str[++start] == ' ');

        //当全部是空白字符时
        if (len <= start) {
            return 0;
        }

        //是正整数还是负整数
        if (str[start] == '-') {
            symbol = -1;
            start++;
        } else if (str[start] == '+') {
            symbol = 1;
            start++;
        }

        for (int i = start; i < len; ++i) {

            if (str[i] > '9' || str[i] < '0') {
                break;
            }

            //查看数组是否越界
            if (res > INT32_MAX / 10 || (res == INT32_MAX / 10 && str[i] - '0' > 7)) {
                if (symbol > 0) {
                    return INT32_MAX;
                } else {
                    return INT32_MIN;
                }

            }
            res = res * 10 + (str[i] - '0');
        }
        return res * symbol;
    }
};

int main(int argc, char **argv) {

    cout << INT32_MIN << "    " << INT32_MAX << endl;
    int count = 8;
    string strs[] = {"42", "   -42", "4193 with words", "words and 987", "-91283472332", "1", "2147483646",
                     "2147483647", "2147483648"};
    int res[] = {42, -42, 4193, 0, -2147483648, 1, 2147483646, 2147483647, 2147483647};

    string flag = "通过全部测试用例";
    for (int i = 0; i < count; ++i) {
        int temp = Solution().myAtoi(strs[i]);
        cout << strs[i] << "  转换后: " << temp << endl << endl;
        if (temp != res[i]) {
            flag = "未通过的测试用例: " + strs[i];
        }
    }

    cout << "测试结果: " << flag << endl;

    return 0;
}

