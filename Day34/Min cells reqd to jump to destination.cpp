#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

int find(vector<vector<int> >& dp, vector<vector<int> >& v, int i, int j, int m, int n, int sum)
{
	if(i < 0 || j < 0 || i >= m || j >= n)
	{
		return INT_MAX;
	}
	
	if(i == m - 1 && j == n - 1)
	{
		ans = min(ans, sum);
		return ans;
	}
	
//	if(dp[i][j] != INT_MAX)
//	{
//		return dp[i][j];
//	}
	
	int a = INT_MAX;
	
//	dp[i][j] = min(dp[i][j], sum);
	a = min(a, find(dp, v, i + v[i][j], j, m, n, sum + 1));
	a = min(a, find(dp, v, i, j + v[i][j], m, n, sum + 1));
	
	dp[i][j] = min(dp[i][j], a);
	return a;
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
	
	vector<vector<int> > dp(m, vector<int>(n, INT_MAX));
	
	dp[0][0] = 1;
	for(int i = 0; i < n; i++)
	{
		if(dp[0][i] != INT_MAX)
		{
			if(i + v[0][i] < n)
			{
				dp[0][i + v[0][i]] = min(dp[0][i + v[0][i]], dp[0][i] + 1);
			}
			if(v[0][i] < m)
			{
				dp[v[0][i]][i] = min(dp[v[0][i]][i], dp[0][i] + 1);
			}
		}
	}
	
	for(int i = 0; i < m; i++)
	{
		if(dp[i][0] != INT_MAX)
		{
			if(v[i][0] < n)
			{
				dp[i][v[i][0]] = min(dp[i][v[i][0]], dp[i][0] + 1);
			}
			if(i + v[0][i] < m)
			{
				dp[i + v[i][0]][0] = min(dp[i + v[i][0]][0], dp[i][0] + 1);
			}
		}
	}
	
	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
		{
			if(dp[i][j] != INT_MAX)
			{
				if(i + v[i][j] < m)
				{
					dp[i + v[i][j]][j] = min(dp[i + v[i][j]][j], dp[i][j] + 1);
				}
				if(j + v[i][j] < n)
				{
					dp[i][j + v[i][j]] = min(dp[i][j + v[i][j]], dp[i][j] + 1);
				}
			}
		}
	}
	
	cout << dp[m - 1][n - 1];
	
//	dp[0][0] = 1;
//	cout << find(dp, v, 0, 0, m, n, 1) << endl;
//	cout << ans;
}
