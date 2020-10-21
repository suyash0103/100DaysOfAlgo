#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

int dp[100][100][100][10];

int find(vector<int>& v, vector<int>& f, int i, int j, int k, int sum, int l)
{
	cout << i << " " << j << " " << k << " " << sum << endl;
	
	if(k == v.size())
	{
		ans = min(ans, sum);
		return sum;
	}
	
	if(j < i)
	{
		return INT_MAX;
	}
	
	if(dp[i][j][k][l] != INT_MAX)
	{
		return dp[i][j][k][l];
	}
	
	int a = INT_MAX;
	
	for(int x = i; x <= j; x++)
	{
		a = min(a, find(v, f, i, x - 1, k + 1, sum + (k + 1) * f[x], 1));
		a = min(a, find(v, f, x + 1, j, k + 1, sum + (k + 1) * f[x], 2));
	}
	
	dp[i][j][k][l] = a;
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
				for(int l = 0; l < 10; l++) 
				{
					dp[i][j][k][l] = INT_MAX;
				}
			}
		}
	}
	
	int n;
	cin >> n;
	
	vector<int> v(n);
	vector<int> f(n);
	
	for(int i = 0; i < n; i++)
		cin >> v[i];
	for(int i = 0; i < n; i++)
		cin >> f[i];
	
	cout << find(v, f, 0, n - 1, 0, 0, 0) << endl;
	cout << ans;
}
