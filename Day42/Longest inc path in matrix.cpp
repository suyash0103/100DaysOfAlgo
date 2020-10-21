#include<bits/stdc++.h>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	
	vector<vector<int> > v(m, vector<int>(n));
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin >> v[i][j];
	
	vector<vector<int> > dp(m, vector<int>(n, 0));
	dp[0][0] = 1;
	int ans = 1;
	for(int i = 1; i < n; i++)
	{
		if(v[0][i] > v[0][i - 1])
		{
			dp[0][i] = dp[0][i - 1] + 1;
		}
		else
		{
			break;
		}
		ans = max(ans, dp[0][i]);
	}
	
	for(int i = 1; i < m; i++)
	{
		if(v[i][0] > v[i - 1][0])
		{
			dp[i][0] = dp[i - 1][0] + 1;
		}
		else
		{
			break;
		}
		ans = max(ans, dp[i][0]);
	}
	
	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
		{
			if(v[i][j] > v[i - 1][j] && dp[i - 1][j] > 0)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
			}
			if(v[i][j] > v[i][j - 1] && dp[i][j - 1] > 0)
			{
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	
	cout << ans;
}
