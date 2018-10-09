//
// Created by wei on 9/25/18.
//

/**
 *
 * 思想:由中心向两边拓展（中心拓展法）
 *
 * 长度为n的字符串最长回文字符串的中心点共有2*n-1个
 *    例如:
 *         babad   ---->b_a_b_a_d (9个 , 此时的中心点就是第一个字符a 或者第二个字符b)
 *         cbba    ---->  c_b_b_a (7个， 此时的中心点就是两个b字符之间的下划线)
 *            上述下划线（表示两个字符之间 ， 实际不存在）也可能是个中心点。
 *
 *
 * 变量的定义，函数的定义，区间的定义  均需要严格，要避免逻辑的混乱。对编程有很大帮助
 *
 *
 */

#include <iostream>

using namespace std;


class Solution {
public:
    /**
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(1)
     *
     * @param s
     * @return
     */
    string longestPalindrome(string s) {

        /**
         * 明确变量的定义，函数的定义，区间的边界问题  避免逻辑的混乱
         *
         * leftI ， rightI，curI 要确保在s[leftI/2 , rightI/2]之间是回文字符串
         *
         * maxStart , maxCount 最长回文串的起始索引和字符数量
         *
         * curStart ， curCount 正在处理的起始索引与字符数量
         */

        int len = s.length();

        int leftI, rightI, curI;
        int maxStart = 0, maxCount = 0;
        int curStart = 0, curCount = 0;

        for (int i = 0, end = 2 * len - 1; i < end; ++i) {

            curI = leftI = rightI = i;
            curStart = curCount = 0;

            if (i % 2 == 0) {
                curCount += 1;
            }

            while (leftI >= 0 && rightI < end) {

                if (leftI != rightI && leftI % 2 == 0) {
                    if (s[leftI / 2] != s[rightI / 2]) {
                        break;
                    } else {
                        curCount += 2;
                    }
                }
                leftI -= 1;
                rightI += 1;
            }


            curStart = (leftI + 2) / 2;
            /* cout << "i: " << i << "   CurCount: " << curCount << "   CurStart: " << curStart << endl;*/

            if (curCount > maxCount) {
                maxStart = curStart;
                maxCount = curCount;
            }
        }

        return s.substr(maxStart, maxCount);

    }
};

int main(int argc, char **argv) {

    string s = "cbba";
    cout << (new Solution())->longestPalindrome(s) << endl;

    return 0;
}

