//
// Created by wei on 9/21/18.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;


/**
 * 思想：双指针分离
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.length() == 0) {
            return 0;
        }

        int front, end, len, lenpre;
        front = 0;
        len = lenpre = 1;
        end = 1;

        //pwwekw
        int sLen = s.length();
        int j;
        while (front >= 0 && end < sLen) {

            for (j = front; j < end; ++j) {
                if (s[j] == s[end]) {
                    break;
                }
            }

            if (j < end) {

                lenpre = (len > lenpre ? len : lenpre);
                front = j + 1;
                len = end - front + 1;

            } else {
                len++;
            }
            end++;
        }
        return (len > lenpre ? len : lenpre);

    }
};


int main(int argc, char **argv) {

    string s = "bbbbb";
    int count = (new Solution())->lengthOfLongestSubstring(s);
    cout << "无重复字符的最长子串长度： " << count << endl;


    return 0;
}