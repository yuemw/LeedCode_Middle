#include "code.h"
//test update
int direct[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

vector<vector<int>> Solution::pacificAtlantic(vector<vector<int>>& matrix)
{
	row = matrix.size();
	col = matrix[0].size();

	if (0 == row || 0 == col)
	{
		return findVec;
	}
	vector<vector<int>> visit1(row, vector<int>(col, 0));
	vector<vector<int>> visit2(row, vector<int>(col, 0));

	for (int i = 0; i < row; ++i)
	{
		DFS1(i, 0, visit1, matrix);
		DFS1(i, col - 1, visit2, matrix);
	}
	for (int j = 0; j < col; ++j)
	{
		DFS1(0, j, visit1, matrix);
		DFS1(row - 1, j, visit2, matrix);
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (visit1[i][j] && visit2[i][j])
			{
				findVec.push_back({ i, j });
			}
		}
	}
	return findVec;
}

bool Solution::DFS1(int x, int y, vector<vector<int>> &visit, const vector<vector<int>> &matrix)
{
	visit[x][y] = 1;
	int x1 = 0;
	int y1 = 0;
	// ио,об,вС,ср
	for (int i = 0; i < 4; ++i)
	{
		x1 = x + direct[i][0];
		y1 = y + direct[i][1];
		if (validPos(x1, y1) && (matrix[x1][y1] >= matrix[x][y]) && !visit[x1][y1]) 
		{
			visit[x1][y1] = 1;
			if (DFS1(x1, y1, visit, matrix))
			{
				return true;
			}
		}
	}

	return false;
};

int Solution::findCircleNum(vector<vector<int>>& M)
{
	int ret = 0;
	row = M.size();
	if (0 == row)
	{
		return 0;
	}
	col = M[0].size();
	if (0 == col)
	{
		return 0;
	}
	
	count = 0;
	vector<vector<int>> visit(row, vector<int>(col));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (0 != M[i][j] && 0 == visit[i][j])
			{
				if (circleDFS(i, j, visit, M) && count > 1)
				{
					++ret;
				}
				count = 0;
			}
		}
	}

	return ret;
}

bool Solution::circleDFS(int x, int y, vector<vector<int>> &visit, const vector<vector<int>> &matrix)
{
	if (x < 0 || x >= row || y < 0 || y >= col)
	{
		return true;
	}

	if (visit[x][y])
	{
		return true;
	}

	if (0 == matrix[x][y])
	{
		return false;
	}

	++count;
	visit[x][y] = 1;
	int newX = 0;
	int newY = 0;
	for (int i = 0; i < 4; ++i)
	{
		newX = x + direct[i][0];
		newY = y + direct[i][1];
		circleDFS(newX, newY, visit, matrix);
	}

	return true;
}

int Solution::coinChange(vector<int>& coins, int amount)
{
	if (0 == amount)
	{
		return 0;
	}
	if (amount < 0)
	{
		return -1;
	}
	
	vector<int> dp(amount + 1, -1);
	dp[0] = 0;
	for (int i = 0; i <= amount; ++i)
	{
		for (int j = 0; j < coins.size(); ++j)
		{
			if (i - coins[j] >= 0 && dp[i - coins[j]] != -1)
			{
				if (dp[i] == -1 || dp[i] > (dp[i - coins[j]] + 1))
				{
					dp[i] = dp[i - coins[j]] + 1;
				}
			}
		}
	}

	return dp[amount];
}

ListNode* Solution::getIntersectionNode(ListNode *headA, ListNode *headB)
{
	ListNode* retList = nullptr;
	ListNode* tmpA = headA;
	ListNode* tmpB = headB;
	
	int lenA = 0;
	int lenB = 0;

	while (nullptr != tmpA)
	{
		++lenA;
		tmpA = tmpA->next;
	}
	while (nullptr != tmpB)
	{
		++lenB;
		tmpB = tmpB->next;
	}

	tmpA = headA;
	tmpB = headB;
	int offset = abs(lenA - lenB);
	while (offset > 0)
	{
		if (lenA > lenB)
		{
			tmpA = tmpA->next;
		}
		else
		{
			tmpB = tmpB->next;
		}
		--offset;
	}

	retList = tmpA;
	bool bSame = false;
	while (nullptr != tmpA)
	{
		if (tmpA->val == tmpB->val)
		{
			if (!bSame)
			{
				retList = tmpA;
			}
			bSame = true;
		}
		else
		{
			bSame = false;
		}
		tmpA = tmpA->next;
		tmpB = tmpB->next;
	}
	
	if (!bSame)
	{
		return false;
	}
	return retList;
}

