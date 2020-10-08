#include<bits/stdc++.h>

using namespace std;

int main()
{
	int l, m, n;
	cin >> l >> m >> n;
	
	vector<vector<vector<int> > > v;
	vector<vector<vector<int> > > dp;
	v.resize(l);
	dp.resize(l);
	
	for(int i = 0; i < l; i++)
	{
		v[i].resize(m);
		dp[i].resize(m);
		for(int j = 0; j < m; j++)
		{
			v[i][j].resize(n);
			dp[i][j].resize(n);
			for(int k = 0; k < n; k++)
			{
				cin >> v[i][j][k];
			}
		}
	}
	
	dp[0][0][0] = v[0][0][0];
	
	for(int i = 1; i < l; i++)
	{
		dp[i][0][0] = dp[i - 1][0][0] + v[i][0][0];
	}
	
	for(int i = 1; i < m; i++)
	{
		dp[0][i][0] = dp[0][i - 1][0] + v[0][i][0];
	}
	
	for(int i = 1; i < n; i++)
	{
		dp[0][0][i] = dp[0][0][i - 1] + v[0][0][i];
	}
	
	for(int i = 1; i < l; i++)
		for(int j = 1; j < m; j++)
			dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + v[i][j][0];
			
	for(int i = 1; i < l; i++)
		for(int j = 1; j < n; j++)
			dp[i][0][j] = max(dp[i - 1][0][j], dp[i][0][j - 1]) + v[i][0][j];
			
	for(int i = 1; i < m; i++)
		for(int j = 1; j < n; j++)
			dp[0][i][j] = max(dp[0][i - 1][j], dp[0][i][j - 1]) + v[0][i][j];
	
	for(int i = 1; i < l; i++)
	{
		for(int j = 1; j < m; j++)
		{
			for(int k = 1; k < n; k++)
			{
				dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1])) + v[i][j][k];
			}
		}
	}
	
	cout << dp[l - 1][m - 1][n - 1];
}
