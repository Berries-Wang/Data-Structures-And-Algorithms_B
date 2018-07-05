#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TestHelper.h"

int findKthLargest(int*, int, int);
int partition(int* , int , int , int *);
int findhelp(int* , int  , int ,int ,int *);


int main(int argc , char **argv)
{

	int nums[] = {3,2,3,1,2,4,5,5,6,10,11,4,18,16,19,23,20,24};
	int target = 4;
	int value = findKthLargest(nums , 18 , target);
	printf("第%d大的数是%d\n",target,value);


	return 0;
}

int partition(int * nums , int left , int right , int *len) //返回第几大的数的序号
{
	int pin = left + rand() % (right - left +1); //枢纽元
	swap(nums + left , nums + pin);

	*len = 1;
	int lt = left;  //arr[left + 1 ....lt] > nums[pin]
	int gt = right;  //arr[lt + 1 ......i-1]  == nums[pin]
	int i = left + 1;    //arr[gt+1 ....right]   <  nums[pin]   i正在处理的元素的索引

	while(i <= gt)
	{

		if(nums[left] < nums[i])
		{
			swap(nums + lt + 1 , nums + i);
			lt ++;
			i ++;
		}
		else if(nums[left] > nums[i])
		{
			swap(nums + gt , nums + i);
			gt --;
		}
		else  
		{ 
			i ++;
			(*len) ++;
		}

	}


	swap(nums + left , nums + lt);
	return lt;

}


int findhelp(int *nums , int left , int right , int k , int *len)
{

	if(right == left)
	{
		return nums[left];  //在这里注意下
	}

	int position = partition(nums ,left , right , len); // 在nums[left ..... right] 中分 ， 左闭右闭

	if(position + 1 <= k && position + (*len) >= k)
	{
		return nums[position];
	}
	else if(position + (*len) < k )
	{
		left = position + (*len);
	}
	else
	{
		right = position - 1;
	}

	return  findhelp(nums , left , right ,k, len);
}


int findKthLargest(int* nums, int numsSize, int k)
{

	srand(time(NULL));

	int len;
	int res = findhelp(nums , 0 , numsSize - 1 , k , &len);

	return res;
}



