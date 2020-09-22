#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int dp[100][100][100];

int find(int n, int m, int k, vector<int>& v)
{
	if(n < 0)
	{
		return 0;
	}
	
	if(n == 0)
	{
		ans++;
		return 1;
	}
	
	if(n > 0 && m == 0)
	{
		return 0;
	}
	
	if(dp[n][m][k] != -1)
	{
		return dp[n][m][k];
	}
	
	int a = find(n, m - 1, k, v);
	int b = 0;
	
	for(int i = 1; i <= k; i++)
	{
		b += find(n - i, m - 1, k, v);
	}
	
	dp[n][m][k] = a + b;
	return a + b;
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			for(int kk = 0; kk <= k; kk++)
			{
				dp[i][j][k] = -1;
			}
		}
	}
	
	vector<int> v(m + 1, k);
	
	cout << find(n, m, k, v);
}
