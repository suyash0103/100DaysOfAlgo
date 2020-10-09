#include<bits/stdc++.h>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	
	vector<vector<int> > ht(m, vector<int>(n));
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> ht[i][j];
		}
	}
	
	vector<vector<int> > dp(m, vector<int>(n));
	dp[0][0] = 0;
	
	for(int i = 1; i < n; i++)
	{
		dp[0][i] = dp[0][i - 1] + abs(ht[0][i - 1] - ht[0][i]);
	}
	
	for(int i = 1; i < m; i++)
	{
		dp[i][0] = dp[i - 1][0] + abs(ht[i - 1][0] - ht[i][0]);
	}
	
	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
		{
			int a = dp[i - 1][j] + abs(ht[i - 1][j] - ht[i][j]);
			int b = dp[i - 1][j - 1] + abs(ht[i - 1][j - 1] - ht[i][j]);
			int c = dp[i][j - 1] + abs(ht[i][j - 1] - ht[i][j]);
			int d = INT_MAX;
			if(j + 1 < n)
			{
				d = dp[i - 1][j + 1] + abs(ht[i - 1][j + 1] - ht[i][j]);
			}
			
			dp[i][j] = min(a, min(b, min(c, d)));
		}
	}
	
	cout << dp[m - 1][n - 1];
}
