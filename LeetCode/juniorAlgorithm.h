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
	//* Description: ��ת
	//************************************
	void rotate(vector<int>& nums, int k);
	//************************************
	//* Method:    removeDuplicates
	//* FullName:  Solution::removeDuplicates
	//* Parameter: vector<int> & nums
	//* Description:ɾ�����������е��ظ���
	//************************************
	int removeDuplicates(vector<int>& nums);
	//************************************
	//* Method:    containsDuplicate
	//* FullName:  Solution::containsDuplicate
	//* Parameter: vector<int> & nums
	//* Description:�����ظ�Ԫ��
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
	//* Method:    intersect Ѱ�����ݺϼ�
	//* FullName:  Solution::intersect
	//* Parameter: vector<int> & nums1
	//* Parameter: vector<int> & nums2
	//* Description:
	//************************************
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2);

};

