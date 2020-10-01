#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int dp[100][100];

int find(int n, int k)
{
//	cout << n << " " << k << endl;
	if(n < 0 || k < 0)
	{
		return 0;
	}
	
	if(n == 0 && k == 0)
	{
		ans++;
		return 1;
	}
	
	if(n == 0 || k == 0)
	{
		return 0;
	}
	
	if(dp[n][k] != -1)
	{
		return dp[n][k];
	}
	
	int a = 0;
	
	for(int i = 0; i <= 9; i++)
	{
		if(n == 1 && i == 0)
		{
			continue;
		}
		if(k >= i)
		{
			a += find(n - 1, k - i);
		}
	}
	
	dp[n][k] = a;
	return a;
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			dp[i][j] = -1;
	
	cout << find(n, k) << endl;
	cout << ans;
}
