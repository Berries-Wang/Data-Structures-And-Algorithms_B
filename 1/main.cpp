#include <iostream>
#include <map>
#include <vector>

/*

map: key 唯一
value  可重复

 */

using namespace std;

class Solution {
	private:
		map<int , int> con;
	public:
		vector<int> twoSum(vector<int>& nums, int target)
		{
			this->con.clear();
			int index = 0;
			vector<int> res;
			res.clear();
			map<int , int>::iterator ite;

			while(index <  nums.size())
			{

				if((ite = this->con.find(target - nums[index])) != this->con.end())
				{
					res.push_back(ite->second);
					res.push_back(index);

					break;
				}
				this->con.insert(pair<int , int>(nums[index] , index));
				index ++;

			}

			return res;

		}
};








int main(int argc , char **argv)
{
	int nums[] = {3 , 2 , 4};
	int target = 6;

	vector<int> numss = vector<int>(nums , nums + sizeof(nums)/sizeof(int));
	vector<int> res  = (new Solution())->twoSum(numss , target);


	for(int i = 0 ; i < res.size();i++)
	{
		cout<<res[i] <<"   ";
	}
	cout<<endl;



	return 0;
}

