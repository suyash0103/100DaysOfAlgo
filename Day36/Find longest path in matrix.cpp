#include<bits/stdc++.h>

using namespace std;

int find(vector<vector<int> >& dp, vector<vector<int> >& v, int i, int j, int m, int n)
{
	if(i < 0 || j < 0 || i >= m || j >= n)
	{
		return 0;
	}
	
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	
	int a = INT_MIN, b = INT_MIN, c = INT_MIN, d = INT_MIN;
	
	if(i - 1 >= 0)
	{
		if((v[i - 1][j] - v[i][j]) == 1)
		{
			a = 1 + find(dp, v, i - 1, j, m, n);
		}
	}
	if(i + 1 < m)
	{
		if((v[i + 1][j] - v[i][j]) == 1)
		{
			b = 1 + find(dp, v, i + 1, j, m, n);
		}
	}
	if(j - 1 >= 0)
	{
		if((v[i][j - 1] - v[i][j]) == 1)
		{
			c = 1 + find(dp, v, i, j - 1, m, n);
		}
	}
	if(j + 1 < n)
	{
		if((v[i][j + 1] - v[i][j]) == 1)
		{
			d = 1 + find(dp, v, i, j + 1, m, n);
		}
	}
	dp[i][j] = max(a, max(b, max(c, max(d, 1))));
	return dp[i][j];
//	ans = max(ans, dp[i][j]);
}

int main()
{
	int m, n;
	cin >> m >> n;
	
	vector<vector<int> > v(m, vector<int>(n));
	vector<vector<int> > dp(m, vector<int>(n, -1));
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin >> v[i][j];
	
	int ans = 1;
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(dp[i][j] == -1)
			{
				find(dp, v, i, j, m, n);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	
	cout << ans;
}
