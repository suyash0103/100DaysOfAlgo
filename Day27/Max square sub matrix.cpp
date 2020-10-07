#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int mat[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> mat[i][j];
	
	int dp[n][n];
	
	int ans = 1;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = 1;
			}
			else
			{
				if(mat[i][j] == mat[i - 1][j] && mat[i][j] == mat[i][j - 1] && mat[i][j] == mat[i - 1][j - 1])
				{
					dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
				}
				else
				{
					dp[i][j] = 1;
				}
			}
			
			ans = max(ans, dp[i][j]);
		}
	}
	
	cout << ans;
}
