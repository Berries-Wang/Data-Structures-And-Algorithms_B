#include <stdio.h>


int binarySearch(int *nums , int endIndex , int target)
{

	int j = 0;
	for(j = 0; j <= endIndex ;j++)
	{
		if(*(nums + j) >= target )
		{
			break;                
		}
	}

	return j;


}


int searchInsert(int* nums, int numsSize, int target) {

	return binarySearch(nums , numsSize - 1 , target);

}




int main(int argc , char **argv)
{

	int arr[] = {1 , 3 , 5 , 6};
	int index1 =  searchInsert(arr , 4 , 5);
	int index2 =  searchInsert(arr , 4 , 2);
	int index3 =  searchInsert(arr , 4 , 7);
	int index4 =  searchInsert(arr , 4 , 0);
	printf("index1 : %d\n" , index1);
	printf("index2 : %d\n" , index2);
	printf("index3 : %d\n" , index3);
	printf("index4 : %d\n" , index4);



	return 0;
}
