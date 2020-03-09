#pragma once

#include <vector>
using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution 
{
public:
	vector<vector<int>> findVec;
	
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix);
	bool DFS1(int x, int y, vector<vector<int>> &visit, const vector<vector<int>> &matrix);
	bool validPos(int x, int y)
	{
		return x >= 0 && y >= 0 && x < row && y < col;
	};

	int findCircleNum(vector<vector<int>>& M);
	bool circleDFS(int x, int y, vector<vector<int>> &visit, const vector<vector<int>> &matrix);

	int coinChange(vector<int>& coins, int amount);

	ListNode* getIntersectionNode(ListNode *headA, ListNode *headB);

public:
	int row, col;
	int count;
};


