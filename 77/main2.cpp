class Solution {
	private:
		vector<bool> visited;
		vector<vector<int> > res;

	public:
		vector<vector<int> > combine(int n, int k)
		{
			this->visited.clear();
			this->visited = vector<bool>(n + 1,false);
			this->res.clear();
			vector<int> none;
			none.clear();

			this->findCombine(none  , 0 , n , k);

			return this->res;

		}
	private:
		void findCombine(vector<int>coll , int order , int n , int k )
		{
			if(order == k)
			{
				this->res.push_back(coll);
				return;
			}


			for(int i = 1; i <= n ; i++ )
			{
				if(this->visited[i] == false)
				{
					for(int j = 1;j <= i;j++)
					{
						this->visited[j] = true;
					}
					coll.push_back(i);
					this->findCombine(coll , order + 1 , n , k);
					for(int j = 1;j <= i;j++)
					{
						this->visited[j] = false;
					}
					coll.pop_back();
				}
			}


		}
};