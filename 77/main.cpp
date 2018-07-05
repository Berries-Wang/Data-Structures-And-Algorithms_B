#include <iostream>
#include <vector>

using namespace std;
//
class Solution {
	private:
		vector<vector<int> > res;

	public:
		vector<vector<int> > combine(int n, int k)
		{
			this->res.clear();
			vector<int> none;
			none.clear();

			if(n <= 0 || k <= 0 ||n < k)
			{
				return this->res;
			}

			this->findCombine(none , n , k , 1);

			return this->res;

		}
	private:
		void findCombine(vector<int>coll , int n , int k  , int start)
		{
			if(coll.size() == k)
			{
				this->res.push_back(coll);
				return;
			}


			for(int i = start; i <= (n - (k - coll.size()) + 1 ); i++ )
			{
				coll.push_back(i);
				this->findCombine(coll , n , k , i + 1);
				coll.pop_back();
			}


		}
};


int main(int argc , char **argv)
{
	vector<vector<int> > res =  (new Solution())->combine(6,2);

	cout<<"个数: " <<res.size()<<endl;
	for(int i =0;i < res.size();i++)
	{
		for(int j = 0;j < res[i].size();j++)
		{
			cout <<res[i][j];
		}
		cout<<endl;
	}

	return 0;
}


