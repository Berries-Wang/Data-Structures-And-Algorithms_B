//
// Created by wei on 9/26/18.
//

/**
 *
 * 动态规划解法：  划分不重复的子问题
 *
 *
定义子问题：dp[i][j] 表示子串s[i…j]是否是回文，我们这样定义实际上变相知道了当前回文子串的长度，以及在原字符串中的位置。
1，初始化：
        1），dp[i][i] = true (0 <= i <= n-1);
        2），if(s[i]==s[i+1]), dp[i][i+1] = true (0 <= i <= n-2);
        3），其余的初始化为false
2,在初始化基础上的递推过程
        如果子问题dp[i+1][j-1] == true，并且扩张一个位置后s[i] == s[j]
显然当前位置，dp[i][j] = true，否则还是为false（意义就是，小的子串都不是回文，在此基础上更大的子串也不是回文）
在动态规划中更新最长回文的长度及起点以及长度即可

**/
#include <iostream>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {

        const int lens = s.length();
        bool flag[1000][1000] = {false};
        int maxStart = 0, maxCount = 1;

        //第一步初始化
        for (int i = 0; i < lens; ++i) {
            flag[i][i] = true;
        }

        //第二步初始化
        for (int j = 0; j < lens - 1; ++j) {
            if (s[j] == s[j + 1]) {
                flag[j][j + 1] = true;
                maxStart = j;
                maxCount = 2;
            }
        }

        //第三步，递推
        for (int i = 3; i <= lens; ++i) {  //字串长度

            for (int j = 0; j < lens - i + 1; ++j) { //字串起始位置
                //字串末尾
                int end = j + i - 1;

                if (s[j] == s[end] && flag[j + 1][end - 1]) {
                    flag[j][end] = true;
                    maxStart = j;
                    maxCount = i;
                }
            }

        }


        return s.substr(maxStart, maxCount);

    }
};


int main(int argc, char **argv) {

    string s = "abcba";
    cout << (new Solution())->longestPalindrome(s) << endl;

    return 0;
}