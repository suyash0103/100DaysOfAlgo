#include<bits/stdc++.h>

using namespace std;

int dp[100][100];

int find(int n, int k)
{
	if(n == 0 || k == 0 || k > n)
	{
		return 0;
	}
	
	if(k == 1 || k == n)
	{
		return 1;
	}
	
	if(dp[n][k] != -1)
		return dp[n][k];
	
	dp[n][k] = k * find(n - 1, k) + find(n - 1, k - 1);
	return dp[n][k];
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			dp[i][j] = -1;
	
	cout << find(n, k);
}
