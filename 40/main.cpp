#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
	private:
		vector<vector<int> > res;
		set<vector<int> >   ress;

	public:
		vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
		{
			this->res.clear();
			vector<int> all;
			all.clear();
			this->ress.clear();
			this->findCombination(candidates , all , 0 , 0 , target);

			this->res = vector<vector<int> >(this->ress.begin() , this->ress.end());
			return this->res;
		}

	private:
		void findCombination(vector<int> &candidates, vector<int> coll, int sum, int startIndex, int target)
		{
			if (sum == target)
			{
				sort(coll.begin() ,coll.end());
				this->ress.insert(coll);
				return;
			}
			else if (sum > target)
			{
				return;
			}
			else
			{

				for (int i = startIndex; i < candidates.size(); i++)
				{
					coll.push_back(candidates[i]);
					this->findCombination(candidates, coll, sum + candidates[i], i + 1, target);
					coll.pop_back();
				}
			}
		}
};

int main(int argc, char **argv)
{

	int candidates[] = {2 , 5 , 2 , 1 , 2};
	vector<int> arr(candidates, candidates + sizeof(candidates) / sizeof(int));
	vector<vector<int> > res = (new Solution())->combinationSum2(arr, 5);

	cout << "共" << res.size() << "组" << endl;

	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << "  ";
		}
		cout << endl;
	}

	return 0;
}
