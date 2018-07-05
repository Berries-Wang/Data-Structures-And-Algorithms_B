#include <stdio.h>


void sortColors(int * , int);
void show(int * , int);
void swap(int * , int *);

int main(int argc , char **argv)
{

	int arr[] = {2,0,2,1,1,0,2,1,0,1,2};
	sortColors(arr , 11);
	show(arr , 11);


	return 0;
}



void swap(int *numa , int *numb)
{
	int temp =*numa;
	*numa = *numb;
	*numb = temp;
}

void sortColors(int* nums, int numsSize) 
{

	int left = 0;;
	int right = numsSize - 1;
	int lt = -1;
	int gt = numsSize-1;
	int i = 0;

	while(i <= gt)
	{
		if(nums[i] == 0)
		{
			swap(nums + i , nums + lt + 1 );
			lt ++;
			i  ++;
		}
		else if(nums[i] == 1)
		{
			i ++;
		}
		else
		{
			swap(nums + i , nums + gt);
			gt --;

		}
	}

}


void show(int *nums , int numsSize)
{
	for(int i = 0;i < numsSize;i++)
	{
		printf("%d\t",nums[i]);
	}

	printf("\n");
}
