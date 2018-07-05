#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  private:
	string dict[10] = {
		" ",
		"",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz"};
	vector<string> res;

  public:
	vector<string> letterCombinations(string digits)
	{
		res.clear();

		this->findCombination(digits, 0, "");

		return this->res;
	}

  private:
	void findCombination(string digits, int index, string s)
	{
		if (index == digits.size())
		{
			if (digits.size() == 0)
			{
				return;
			}

			this->res.push_back(s);
			return;
		}

		for (int i = 0; i < this->dict[digits[index] - '0'].size(); i++)
		{
			string st = s + (this->dict[digits[index] - '0'])[i];
			this->findCombination(digits, index + 1, st);
		}
	}
};

int main(int argc, char **argv)
{

	if (argc < 2)
	{
		cout << "too few arguments" << endl;
		exit(1);
	}

	string di = argv[1];
	vector<string> res = (new Solution())->letterCombinations(di);

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << "    " << i + 1 << endl;
	}

	return 0;
}
