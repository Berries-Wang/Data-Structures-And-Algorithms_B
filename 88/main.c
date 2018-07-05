#include <stdio.h>

void merge(int*, int, int* , int);
void show(int*, int);

int main(int argc , char **argv)
{

	int arr1[] = {0,0,3,0,0,0,0,0,0};
	int arr2[] = {-1,1,1,1,2,3};

	merge(arr1 , 3 , arr2 , 6);
	show(arr1 , 9);


	return 0;
}


void merge(int* nums1, int m, int* nums2, int n)
{
	int length = m + n;

	while( n > 0)
	{
		if(nums2[n - 1] > nums1[m - 1])
		{
			nums1[--length] = nums2[--n];
		}
		else  //nums2[n - 1] <= nums1[m - 1]
		{
			nums1[--length] = nums1[--m];
		}

		if(m == 0 && n != 0)
		{
			for(int i = 0;i < n;i++)
			{
				nums1[i] = nums2[i];
			}
			break;
		}

	}

}

void show(int *arr , int numsSize)
{
	for(int i = 0;i < numsSize;i++)
	{
		printf("%-5d",arr[i]);
	}

	printf("\n");
}
