#include<bits/stdc++.h>

using namespace std;

int ans = 0;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(int n, int prev)
{
	if(n == 0)
	{
		ans++;
		return 1;
	}
	
	if(dp[n][prev] != -1)
	{
		return dp[n][prev];
	}
	
	int a = 0;
	
	if(prev == 10)
	{
		for(int i = 1; i <= 9; i++)
		{
			a += find(n - 1, i);
		}
	}
	else
	{
		if(prev + 1 <= 9)
		{
			a += find(n - 1, prev + 1);
		}
		if(prev - 1 >= 0)
		{
			a += find(n - 1, prev - 1);
		}
	}
	
	dp[n][prev] = a;
	
	return a;
}

int main()
{
	int n;
	cin >> n;
	
	if(n == 1)
	{
		cout << 10;
		return 1;
	}
	
	cout << find(n, 10) << endl;
	cout << ans;
}
