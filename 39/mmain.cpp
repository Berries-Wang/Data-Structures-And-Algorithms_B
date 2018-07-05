#include <iostream>
#include <vector>

using namespace std;


class Solution {
	private:
		vector<vector<int> > res;
	public:
		vector<vector<int> > combinationSum(vector<int>& candidates, int target) {

			res.clear();
			vector<int> none;
			none.clear();

			this->findCombine(candidates , none , 0 , target , 0);

			return this->res;
		}


	private:
		void findCombine(vector<int>& candidates , vector<int> coll , int sum , int target , int startIndex)
		{
			if(sum == target)
			{
				this->res.push_back(coll);
				return;
			}
			else if(sum > target)
			{
				return;
			}

			for(int i = startIndex;i < candidates.size();i++)
			{

				coll.push_back(candidates[i]);
				this->findCombine(candidates , coll,sum + candidates[i] , target , i);
				coll.pop_back();

			}

		}
};



int main(int argc , char **argv)
{

	int candidates[] = {2 , 3 ,6,7};
	vector<int> arr(candidates , candidates + sizeof(candidates)/sizeof(int));
	vector<vector<int> > res = (new Solution())->combinationSum(arr , 7);

	cout<<"共"<<res.size()<<"组"<<endl;


	for(int i = 0; i < res.size();i++)
	{
		for(int j = 0; j < res[i].size();j++)
		{
			cout<<res[i][j]<<"  ";
		}
		cout<<endl;
	}




	return 0;
}
