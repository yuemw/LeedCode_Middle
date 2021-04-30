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

#include <set>
bool Solution::containsDuplicate(vector<int>& nums)
{
	std::set<int> tmpSet;
	for (int i = 0; i < nums.size(); ++i)
	{
		tmpSet.insert(nums[i]);
	}

	return tmpSet.size() != nums.size();
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

std::vector<int> Solution::plusOne(vector<int>& digits)
{
	for (int i = digits.size() - 1; i >= 0; i--) {
		if (digits[i] != 9) 
		{
			digits[i]++;
			return digits;
		}
		else 
		{
			digits[i] = 0;
		}
	}
	vector<int> retVec(digits.size() + 1, 0);
	retVec[0] = 1;

	return retVec;
}

#include <algorithm>
std::vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	int size = nums.size();
	vector<int> retVec;
	for (int i = 0; i < size - 1 ; ++i)
	{
		int temp = target - nums[i];
		if (temp <= 0)
		{
			break;
		}
		for (int j = i + 1; j < size; ++j)
		{
			if (nums[j] == temp)
			{
				retVec.push_back(i);
				retVec.push_back(j);
				return retVec;
			}
		}
	}

	return retVec;
}

void Solution::moveZeroes(vector<int>& nums)
{
	if (nums.size() <= 1)
	{
		return;
	}

	int index = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (0 != nums[i])
		{
			nums[index++] = nums[i];
		}
	}

	memset(nums.data() + index , 0, (nums.size() - index) * sizeof(int));

	int i = 0;
}
#include <iostream>
bool Solution::isValidSudoku(vector<vector<char>>& board)  
{
	int row[9][9] = { 0 };
	int column[9][9] = { 0 };
	int cell[9][9] = { 0 };
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if ('.' == board[i][j])
			{
				continue;
			}

			int temp = board[i][j] - '0' - 1;
			int box_index = i / 3 * 3 + j / 3;
			if (row[i][temp] == 1 || column[j][temp] == 1 || cell[box_index][temp] == 1) 
			{ 
				return false;
			}

			++row[i][temp];
			++column[j][temp];
			++cell[box_index][temp];
		}

	}

	return true;
}


void Solution::rotate(vector<vector<int>>& matrix)
{
	int length = matrix.size();
	if (length <= 1)
	{
		return;
	}

	vector<int> tmpVec;
	for (int i = 0; i < length / 2; ++i)
	{
		tmpVec = matrix[i];
		matrix[i] = matrix[length - i - 1];
		matrix[length - i - 1] = tmpVec;
	}

	for (int i = 0; i < length; ++i)
	{
		int tmp = 0;
		for (int j = i + 1; j < length; ++j)
		{
			tmp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = tmp;
		}
	}
}

