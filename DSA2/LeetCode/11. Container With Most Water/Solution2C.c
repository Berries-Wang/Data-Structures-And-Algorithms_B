//
// Created by wei on 10/13/18.
//
#include <stdio.h>
#include <time.h>


#define MIN(E1, E2) ((E1) > (E2)?(E2):(E1))
#define MAX(E1, E2) ((E1) > (E2)?(E1):(E2))

int maxArea(int *height, int heightSize) {


    int left = 0;
    int right = heightSize - 1;
    int maxArea = 0;
    int curArea = 0;

    while (left < right) {

        curArea = MIN(*(height + left), *(height + right)) * (right - left);

        maxArea = MAX(maxArea, curArea);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }

    }

    return maxArea;
}


void test(int *height, int heightSize, int (*maxAreaP)(int *height, int heightSize), char *name) {


    clock_t start = clock();

    maxAreaP(height, heightSize);

    clock_t end = clock();

    double use = (((double) end) - start) / CLOCKS_PER_SEC;
    printf("%s : 耗时%lf\n", name, use);


}

int main(int argc, char **argv) {

    int TestData[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    test(TestData, sizeof(TestData) / sizeof(int), maxArea, "C 语言双指针解法");

    return 0;
}