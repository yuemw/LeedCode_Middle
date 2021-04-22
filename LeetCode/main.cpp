#include "juniorAlgorithm.h"
#include <iostream>
using namespace std;


void test()
{
	string str = "ABCaD";
	char aim;
//	cin >> str;
	cin >> aim;

	int ret = 0;
	int count = 0;
	int size = str.size();
	for (int i = 0; i < size; ++i)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			ret = abs(aim - str[i]);
			if (0 == ret || 32 == ret)
			{
				++count;
			}
		}
		else if (0 == (aim ^ str[i]))
		{
			++count;
		}
	}

	cout << count << endl;
}


int main()
{
	Solution obj;
	//	vector<vector<int>> vec{ { 1, 2, 2, 3, 5 }, { 3, 2, 3, 4, 4 }, { 2, 4, 5, 3, 1 }, { 6, 7, 1, 4, 5 }, { 5, 1, 1, 2, 4 } };
	//	obj.pacificAtlantic(vec);

	// 	vector<vector<int>> vec{ { 1,1,0}, { 1,1,0}, { 0,0,1}};
	// 	cout << obj.findCircleNum(vec) << endl;

	vector<int> vec{ 7, 1, 5, 3, 6, 4, 3 };
// 	cout << obj.coinChange(vec, 9084) << endl;
//	obj.removeDuplicates(vec);
//	bool ret = obj.containsDuplicate(vec);
	int ret = obj.maxProfit(vec);
	cout << "max profit is " << ret << endl;
	obj.intersect(vec, vec);

	system("pause");
}
