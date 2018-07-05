#include <stdio.h>
#include <stdlib.h>
#include "TestHelper.h"

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize);

int main(int argc , char **argv)
{

	int numbers[]  =  { 2, 7, 11, 15 };
	int size;
	int *res = twoSum(numbers , 4 , 9 , &size);

	show(res , 2);

	return 0;
}


int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{

	int index1 = 0;
	int index2 = numbersSize - 1;

	while(1)
	{
		if(numbers[index1] + numbers[index2] > target)
		{
			index2 --;
		}
		else if(numbers[index1] + numbers[index2] < target)
		{
			index1 ++;
		}
		else // numbers[index1] + numbers[index2] == target
		{
			break;
		}
	}

	*returnSize = 2;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	if(res == NULL)
	{
		exit(1);
	}
	res[0] = index1 + 1;
	res[1] = index2 + 1;

	return res;

}
