#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int dp[100][100][100];

int find(int n, int odd, int even)
{
	if(n == 0)
	{
		if((even - odd) == 1)
		{
			ans++;
			return 1;
		}
		return 0;
	}
	
	if(dp[n][odd][even] != -1)
	{
		return dp[n][odd][even];
	}
	
	int a = 0;
	
	for(int i = 0; i <= 9; i++)
	{
		if(n == 1 && i == 0)
		{
			continue;
		}
		if((n - 1) % 2 == 0)
		{
			a += find(n - 1, odd, even + i);
		}
		else
		{
			a += find(n - 1, odd + i, even);
		}
	}
	
	dp[n][odd][even] = a;
	return a;
}

int main()
{
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			for(int k = 0; k < 100; k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}
	
	int n;
	cin >> n;
	
	cout << find(n, 0, 0) << endl;
//	cout << ans;
}
