#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int dp[50][50][50][50];

int find(int m, int n, int k, int dir)
{
	if(m == 0 || n == 0)
	{
		return 0;
	}
	
	if(m == 1 && n == 1)
	{
		ans++;
		return 1;
	}
	
	if(dp[m][n][k][dir] != -1)
	{
		return dp[m][n][k][dir];
	}
	
	int a = 0;
	
	if(dir == -1)
	{
		a += find(m - 1, n, k, 0);
		a += find(m, n - 1, k, 1);
	}
	else
	{
		if(dir == 1)
		{
			a += find(m, n - 1, k, 1);
			if(k > 0)
			{
				a += find(m - 1, n, k - 1, 0);
			}
		}
		else
		{
			a += find(m - 1, n, k, 0);
			if(k > 0)
			{
				a += find(m, n - 1, k - 1, 1);
			}
		}
	}
	
	dp[m][n][k][dir] = a;
	return a;
}

int main()
{
	int m, n;
	cin >> m >> n;
	
	int k;
	cin >> k;
	
	for(int i = 0; i < 50; i++)
		for(int j = 0; j < 50; j++)
			for(int k = 0; k < 50; k++)
				for(int l = 0; l < 50; l++)
					dp[i][j][k][l] = -1;
	
	cout << find(m, n, k, -1) << endl;
	cout << ans;
}
