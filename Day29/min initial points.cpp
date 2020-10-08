#include<bits/stdc++.h>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	
	vector<vector<int> > dp(m, vector<int>(n));
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> dp[i][j];
		}
	}
	
	vector<vector<int> > sums(m, vector<int>(n));
	
	if(dp[m - 1][n - 1] > 0)
	{
		sums[m - 1][n - 1] = 1;
	}
	else
	{
		sums[m - 1][n - 1] = abs(dp[m - 1][n - 1]) + 1;
	}
	
	for(int i = m - 2; i >= 0; i--)
	{
		if(dp[i][n - 1] > 0)
		{
			if(dp[i][n - 1] >= sums[i + 1][n - 1])
			{
				sums[i][n - 1] = 1;
			}
			else
			{
				sums[i][n - 1] = sums[i + 1][n - 1] - dp[i][n - 1];
			}
		}
		else
		{
			sums[i][n - 1] = abs(dp[i][n - 1]) + sums[i + 1][n - 1];
		}
	}
	
	for(int i = n - 2; i >= 0; i--)
	{
		if(dp[m - 1][i] > 0)
		{
			if(dp[m - 1][i] >= sums[m - 1][i + 1])
			{
				sums[m - 1][i] = 1;
			}
			else
			{
				sums[m - 1][i] = sums[m - 1][i + 1] - dp[m - 1][i];
			}
		}
		else
		{
			sums[m - 1][i] = abs(dp[m - 1][i]) + sums[i + 1][m - 1];
		}
	}
	
	for(int i = m - 2; i >= 0; i--)
	{
		for(int j = n - 2; j >= 0; j--)
		{
			int p = min(sums[i + 1][j], sums[i][j + 1]);
//			cout << i << " " << j << " " << p << endl;
			if(dp[i][j] > 0)
			{
				if(dp[i][j] > p)
				{
					sums[i][j] = 1;
				}
				else
				{
					sums[i][j] = p - dp[i][j];
				}
			}
			else
			{
				sums[i][j] = abs(dp[i][j]) + p;
			}
		}
	}
	
	cout << endl;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << sums[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << sums[0][0];
}
