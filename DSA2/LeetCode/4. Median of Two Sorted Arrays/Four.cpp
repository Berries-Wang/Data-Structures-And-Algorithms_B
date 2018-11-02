//
// Created by wei on 9/21/18.
//

#include <iostream>
#include <vector>


using namespace std;



//思想：归并

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {


        vector<int> nums3;
        int index1, index2;
        index1 = index2 = 0;

        int len1 = nums1.size();
        int len2 = nums2.size();

        while (index1 < len1 && index2 < len2) {

            if (nums1[index1] < nums2[index2]) {
                nums3.push_back(nums1[index1]);
                index1++;
            } else {
                nums3.push_back(nums2[index2]);
                index2++;
            }
        }

        int index3 = 0;
        vector<int> *pnums = NULL;
        if (index1 >= len1 && index2 < len2) {

            index3 = index2;
            pnums = &nums2;

        } else if (index1 < len1 && index2 >= len2) {
            index3 = index1;
            pnums = &nums1;
        }

        for (int i = index3; i < pnums->size(); i++) {
            nums3.push_back((*pnums)[i]);
        }

        for (int j = 0; j < nums3.size(); ++j) {
            cout << nums3[j] << "  ";
        }
        cout << endl;

        int mid = nums3.size() / 2;
        if (nums3.size() % 2 == 0) {
            return (static_cast<double>(nums3[mid]) + nums3[mid - 1]) / 2;
        } else {
            return nums3[mid];
        }


    }
};


int main(int argc, char **argv) {

    int arr1[] = {3};
    int arr2[] = {-2, -1};

    vector<int> nums1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> nums2(arr2, arr2 + sizeof(arr2) / sizeof(int));

    double midNum = (new Solution())->findMedianSortedArrays(nums1, nums2);
    cout << "中位数: " << midNum << endl;

    return 0;

}


