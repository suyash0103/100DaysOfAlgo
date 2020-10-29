#include<bits/stdc++.h>

using namespace std;

//int ans = 0;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(int n, int prev)
{
	if(n == 0)
	{
		return 1;
	}
	
	if(dp[n][prev] != -1)
	{
		return dp[n][prev];
	}
	
	int a = 0;
	
	for(int i = prev; i <= 9; i++)
	{
		a += find(n - 1, i);
	}
	
	dp[n][prev] = a;
	return a;
}

int main()
{
	int n;
	cin >> n;
	
	cout << find(n, 0) << endl;
//	cout << ans;
}
