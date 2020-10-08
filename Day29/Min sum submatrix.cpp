#include<bits/stdc++.h>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	
	vector<vector<int> > dp(m, vector<int>(n));
	
	int ans = INT_MAX;
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> dp[i][j];
			ans = min(ans, dp[i][j]);
		}
	}
	
	for(int i = 1; i < n; i++)
	{
		dp[0][i] += dp[0][i - 1];
	}
	
	for(int i = 1; i < m; i++)
	{
		dp[i][0] += dp[i - 1][0];
	}
	
	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
		{
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			ans = min(ans, dp[i][j]);
		}
	}
	
	
	cout << endl;
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	
	for(int k = 2; k <= min(m, n); k++)
	{
		for(int i = k - 1; i < m; i++)
		{
			for(int j = k - 1; j < n; j++)
			{
				if(i - k < 0 && j - k < 0)
				{
					continue;
				}
				
				if(i - k < 0)
				{
					int curr = dp[i][j] - dp[i][j - k];
					ans = min(ans, curr);
				}
				
				else if(j - k < 0)
				{
					int curr = dp[i][j] - dp[i - k][j];
					ans = min(ans, curr);
				}
				
				else
				{
					int curr = dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k];
					ans = min(ans, curr);
				}
			}
		}
	}
	
	cout << ans;
}
