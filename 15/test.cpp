#include <iostream>
#include "main_bug.h"
#include <ctime>
#include <vector>

using namespace std;

int main(int argc , char **argv)
{

	int nums[] = {-1, 0, 1, 2, -1, -4};
	vector<int> numss = vector<int>(nums , nums + sizeof(nums)/sizeof(int));

    
    clock_t start = clock();
	vector<vector<int> > res = (new Solution_bug())->threeSum(numss);
	clock_t   end = clock();
	cout<<"time1: "<<(((double)end) - start)/CLOCKS_PER_SEC<<" S"<<endl;



	cout<<"共 "<<res.size()<<" 组"<<endl;

	for(int i = 0 ; i < res.size();i++)
	{
		for(int j = 0;j < res[i].size();j++)
		{
			cout<<res[i][j] <<"   ";
		}
		cout<<endl;
	}




	return 0;
}