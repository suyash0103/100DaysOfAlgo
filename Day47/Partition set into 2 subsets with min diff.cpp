#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

int dp[100][100][100];

int find(vector<int>& v, int n, int i, int sum1, int sum2)
{
	if(i == v.size())
	{
		ans = min(ans, abs(sum1 - sum2));
		return ans;
	}
	
	if(dp[i][sum1][sum2] != -1)
	{
		return dp[i][sum1][sum2];
	}
	
	int a = INT_MAX;
	
	a = min(a, find(v, n, i + 1, sum1 + v[i], sum2));
	a = min(a, find(v, n, i + 1, sum1, sum2 + v[i]));
	
	dp[i][sum1][sum2] = a;
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
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	cout << find(v, n, 0, 0, 0) << endl;
	cout << ans;
}
