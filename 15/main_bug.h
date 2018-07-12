#ifndef MAIN_BUG_H_
#define MAIN_BUG_H_

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

class Solution_bug {
	private:
		map<int , int > con;
		set<vector<int> > mom;
	public:
		Solution_bug()
		{
			this->con.clear();
		}

		vector<vector<int> > threeSum(vector<int>& nums)
		{
			vector<int> ress;
			map<int , int> hh;

			for(int i = 0;i < nums.size();i++)
			{
				hh[nums[i]] = i;				
			}
			map<int , int >::iterator ite;
			for(ite = hh.begin() ; ite != hh.end(); ite++ )
			{
				ress.clear();
				ress.push_back((*ite).first);
				this->findTwoSum(nums , ress , (*ite).second  , 0 - (*ite).first);
				this->con.clear();
			}

			vector<vector<int> > res = vector<vector<int> >(this->mom.begin() , this->mom.end());

			return res;

		}
	private:
		void findTwoSum(vector<int>& resource , vector<int> res , int index , int target)
		{
			map<int , int>::iterator ite;
			int curIndex = 0;
			while( curIndex < resource.size())
			{
				if(curIndex == index)
				{
					curIndex ++;
					continue;
				}

				if((ite = this->con.find(target - resource[curIndex])) != this->con.end())
				{
					res.push_back(resource[curIndex]);
					res.push_back(target - resource[curIndex]);

					vector<int> now(res.begin() , res.end());

					sort(now.begin() , now.end());

					this->mom.insert(now);

					res.pop_back();
					res.pop_back();
				}

				this->con.insert(pair<int , int>(resource[curIndex] , curIndex));
				curIndex ++;
			}

		}
};

#endif





