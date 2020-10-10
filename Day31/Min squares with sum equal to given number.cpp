#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(int n, int t)
{
	if(n == 0)
	{
		ans = min(ans, t);
		return t;
	}
	
	if(dp[n][t] != -1)
	{
		return dp[n][t];
	}
	
	int a = INT_MAX;
	
	for(int i = 1; i <= pow(n, 0.5); i++)
	{
		a = min(a, find(n - i * i, t + 1));
	}
	
	dp[n][t] = a;
	return a;
}

int main()
{
	int n;
	cin >> n;
	
	int root = pow(n, 0.5);
	
	if(root * root == n)
	{
		cout << root;
	}
	else
	{
		cout << find(n, 0) << endl;
		cout << ans;
	}
}
