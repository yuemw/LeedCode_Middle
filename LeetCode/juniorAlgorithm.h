#pragma once

#include <vector>
using namespace std;


class Solution {
public:
	Solution(){};

	//************************************
	//* Method:    rotate
	//* FullName:  Solution::rotate
	//* Parameter: vector<int> & nums
	//* Parameter: int k
	//* Description: 反转
	//************************************
	void rotate(vector<int>& nums, int k);
	//************************************
	//* Method:    removeDuplicates
	//* FullName:  Solution::removeDuplicates
	//* Parameter: vector<int> & nums
	//* Description:删除排序数组中的重复项
	//************************************
	int removeDuplicates(vector<int>& nums);
	//************************************
	//* Method:    containsDuplicate
	//* FullName:  Solution::containsDuplicate
	//* Parameter: vector<int> & nums
	//* Description:存在重复元素
	//************************************
	bool containsDuplicate(vector<int>& nums);
	//************************************
	//* Method:    maxProfit
	//* FullName:  Solution::maxProfit
	//* Parameter: vector<int> & prices
	//* Description:
	//************************************
	int maxProfit(vector<int>& prices);
	//************************************
	//* Method:    intersect 寻找数据合集
	//* FullName:  Solution::intersect
	//* Parameter: vector<int> & nums1
	//* Parameter: vector<int> & nums2
	//* Description:
	//************************************
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
	//************************************
	//* Method:    plusOne 加一
	//* FullName:  Solution::plusOne
	//* Parameter: vector<int> & digits
	//* Description:
	//************************************
	vector<int> plusOne(vector<int>& digits);
	//************************************
	//* Method:    twoSum 两数之和
	//* FullName:  Solution::twoSum
	//* Parameter: vector<int> & nums
	//* Parameter: int target
	//* Description:
	//************************************
	vector<int> twoSum(vector<int>& nums, int target);
	//************************************
	//* Method:    moveZeroes 移动零
	//* FullName:  Solution::moveZeroes
	//* Parameter: vector<int> & nums
	//* Description:
	//************************************
	void moveZeroes(vector<int>& nums);
	//************************************
	//* Method:    isValidSudoku 有效的数独
	//* FullName:  Solution::isValidSudoku
	//* Parameter: vector<vector<char>> & board
	//* Description:
	//************************************
	bool isValidSudoku(vector<vector<char>>& board);
	//************************************
	//* Method:    rotate 翻转图像
	//* FullName:  Solution::rotate
	//* Parameter: vector<vector<int>> & matrix
	//* Description:
	//************************************
	void rotate(vector<vector<int>>& matrix);
};

