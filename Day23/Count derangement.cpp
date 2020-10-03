#include<bits/stdc++.h>

using namespace std;

int ans = 0;

vector<int> dp(100, -1);

int find(int n)
{
	if(n == 0)
	{
		return 1;
	}
	
	if(n == 1)
	{
		return 0;
	}
	
	if(dp[n] != -1)
	{
		return dp[n];
	}
	
	dp[n] = (n - 1) * (find(n - 1) + find(n - 2));
	return dp[n];
}

int main()
{
	int n;
	cin >> n;
	
	cout << find(n);
}
