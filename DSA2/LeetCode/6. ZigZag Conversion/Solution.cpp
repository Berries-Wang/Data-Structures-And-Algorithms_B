//
// Created by wei on 9/26/18.
//

/**
 *
 *
 * 使用数据结构来辅助解答
 *
 *
 */
#include <iostream>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {

        int lens = s.length();

        if (lens <= numRows || numRows == 1) {
            return s;
        }

        int groupNum = 2 * (numRows - 1);  //一组有多少个元素
        int cols = numRows - 1;
        char res[lens];

        int group = cols * (lens % groupNum == 0 ? (lens / groupNum) : (lens / groupNum + 1));
        char helper[numRows][group];
        //初始化
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < group; ++j) {
                helper[i][j] = ' ';
            }
        }

        int curIndex = 0;
        for (int i = 0; i < group; ++i) {
            for (int j = 0; j < numRows; ++j) {

                if (curIndex >= lens) {
                    break;
                }
                if (i % (numRows - 1) == 0) {
                    helper[j][i] = s[curIndex];
                    curIndex++;
                } else {
                    int temp = i % (numRows - 1);
                    if (j == numRows - 1 - temp) {
                        helper[j][i] = s[curIndex];
                        curIndex++;
                    }
                }

            }
        }
        curIndex = 0;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < group; ++j) {
                if (helper[i][j] != ' ') {
                    res[curIndex] = helper[i][j];
                    curIndex++;
                }
            }
        }
        string re(res);

        return re.substr(0, lens);

    }
};

int main(int argc, char **argv) {

    string test = "PAYPALISHIRING";
    cout << Solution().convert(test, 3) << endl;

    return 0;
}
