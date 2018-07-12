#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

class Solution {
	public:
		int firstUniqChar(string s)
		{
			int dict[26] ={0};

			for(int i = 0;i < s.size(); i++)
			{
				dict[s[i] - 'a'] ++;
			}

			for(int i = 0; i < s.size();i++)
			{
				if(dict[s[i] - 'a'] == 1)
				{
					return i;
				}
			}

			return -1;

		}
};








int main(int argc , char **argv)
{
	if(argc < 2)
	{
		cout<<"too few arguments"<<endl;
		exit(1);
	}

	string s(argv[1]);

	cout<<(new Solution())->firstUniqChar(s)<<endl;
	return 0;
}
