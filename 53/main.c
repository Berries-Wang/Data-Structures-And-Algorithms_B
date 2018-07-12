#include <stdio.h>

int maxSubArray(int* nums, int numsSize)
{
	int thisSum = 0;
	int maxSum = 0;
	int max = *(nums + 0);

	for(int i = 0; i < numsSize;i++)
	{
		if(max < *(nums + i))
		{
			max = *(nums + i);
		}

		thisSum += *(nums + i);

		if(thisSum > maxSum)
		{
			maxSum = thisSum;
		}
		else if(thisSum < 0)
		{
			thisSum = 0;
		}
	}

	if(maxSum == 0)
	{
		return max;
	}

	return maxSum;

}


int main(int argc , char **argv)
{

	//int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
	int arr[] = {-5};

	printf("the maxsubarr is: %d\n" , maxSubArray(arr , sizeof(arr)/sizeof(int)));



	return 0;
}
