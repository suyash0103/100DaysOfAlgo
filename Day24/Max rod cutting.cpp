#include<bits/stdc++.h>

using namespace std;

int ans = 0;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(int n, int prod)
{
	if(n < 0)
	{
		return 0;
	}
	
	if(n == 0)
	{
		ans = max(ans, prod);
		return prod;
	}
	
	if(dp[n][prod] != -1)
	{
		return dp[n][prod];
	}
	
	int a = 0;
	
	for(int i = 1; i <= n; i++)
	{
		a = max(a, find(n - i, prod * i));
	}
	
	dp[n][prod] = max(a, dp[n][prod]);
	return a;
}

int main()
{
	int n;
	cin >> n;
	
	find(n, 1);
	cout << ans;
}
