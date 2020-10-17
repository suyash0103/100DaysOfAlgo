#include<bits/stdc++.h>

using namespace std;

int find(vector<vector<int> >& dp, vector<vector<int> >& v, int i, int j)
{
	if(i < 0 || j < 0 || i >= dp.size() || j >= dp[0].size())
	{
		return 0;
	}
	
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	
	int a = INT_MIN;
	
	if(i - 1 >= 0 && v[i - 1][j] == v[i][j] + 1)
	{
		a = 1 + max(a, find(dp, v, i - 1, j));
	}
	
	if(i + 1 < dp.size() && v[i + 1][j] == v[i][j] + 1)
	{
		a = 1 + max(a, find(dp, v, i + 1, j));
	}
	
	if(j - 1 >= 0 && v[i][j - 1] == v[i][j] + 1)
	{
		a = 1 + max(a, find(dp, v, i, j - 1));
	}
	
	if(j + 1 < dp[0].size() && v[i][j + 1] == v[i][j] + 1)
	{
		a = 1 + max(a, find(dp, v, i, j + 1));
	}
	
	if(i - 1 >= 0 && j - 1 >= 0 && v[i - 1][j - 1] == v[i][j] + 1)
	{
		a = 1 + max(a, find(dp, v, i - 1, j - 1));
	}
	
	if(i - 1 >= 0 && j + 1 < dp[0].size() && v[i - 1][j + 1] == v[i][j] + 1)
	{
		a = 1 + max(a, find(dp, v, i - 1, j + 1));
	}
	
	if(i + 1 < dp.size() && j - 1 >= 0 && v[i + 1][j - 1] == v[i][j] + 1)
	{
		a = 1 + max(a, find(dp, v, i + 1, j - 1));
	}
	
	if(i + 1 < dp.size() && j + 1 < dp[0].size() && v[i + 1][j + 1] == v[i][j] + 1)
	{
		a = 1 + max(a, find(dp, v, i + 1, j + 1));
	}
	
	dp[i][j] = max(a, 1);
	return dp[i][j];
}

int main()
{
	int m, n;
	cin >> m >> n;
	
	vector<vector<int> > v(m, vector<int>(n));
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}
	
	vector<vector<int> > dp(m, vector<int>(n, -1));
	int ch;
	cin >> ch;
	
	int ans = 1;
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(dp[i][j] == -1 && v[i][j] == ch)
			{
				find(dp, v, i, j);
			}
			
			ans = max(ans, dp[i][j]);
		}
	}
	
	cout << ans;
}
