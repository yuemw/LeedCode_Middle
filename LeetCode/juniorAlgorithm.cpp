#include "juniorAlgorithm.h"
#include <map>
using namespace std;

void Solution::rotate(vector<int>& nums, int k)
{
	if (nums.empty() || 0 == k)
	{
		return;
	}

	int size = nums.size();
	if (abs(k) > size)
	{
		k = k % size;
	}

	for (int index = 0; index < size - k; ++index)
	{
		nums.push_back(nums[index]);
	}

	vector<int>::iterator start = nums.begin();
	vector<int>::iterator end = nums.begin() + size - k;
	nums.erase(start, end);

}

int Solution::removeDuplicates(vector<int>& nums)
{
	if (nums.empty() || nums.size() == 1)
	{
		return nums.size();
	}
	int i = 0;
	for (int j = 1; j < nums.size(); ++j) 
	{
		if (nums[i] != nums[j]) 
		{
			i++;
			nums[i] = nums[j];
		}
	}
	nums.erase(nums.begin() + i + 1, nums.end());

	return nums.size();
}

bool Solution::containsDuplicate(vector<int>& nums)
{
	if (nums.size() <= 1)
	{
		return false;
	}
	if (nums[0] == nums[1])
	{
		return true;
	}

	bool bFind = false;
	for (int i = 0; i < nums.size() - 1; ++i)
	{
		int j = i + 1;
		int ret = nums[i];
		for (; j < nums.size(); ++j)
		{
			ret = ret ^ nums[j];
			if (nums[i] == ret)
			{
				return true;
			}
		}
	}

	return false;
}

int Solution::maxProfit(vector<int>& prices)
{
	int vecSize = prices.size();
	if (vecSize < 2)
	{
		return 0;
	}

	vector<vector<int>> opsVec;
	int profit = 0;
	int tempProfit = 0;
	for (int index = 1; index < vecSize; ++index)
	{
		tempProfit = prices[index] - prices[index - 1];
		if (tempProfit > 0)
		{
			profit += tempProfit;
		}
	}

	return profit;
}

std::vector<int> Solution::intersect(vector<int>& nums1, vector<int>& nums2)
{
	if (nums1.size() > nums2.size())
	{
		return intersect(nums2, nums1);
	}

	std::map<int, int> map;
	for (int num : nums1)
	{
		map[num] += 1;
	}

	vector<int> retVec;
	for (int num : nums2)
	{
		if (map.find(num) != map.end() && map[num] > 0)
		{
			map[num] -= 1;
			retVec.push_back(num);
		}
	}

	return retVec;
}
