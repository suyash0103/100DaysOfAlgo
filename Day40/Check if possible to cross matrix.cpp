#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int dp[100][100][100];

bool find(vector<vector<int> >& v, int n, int m, int i, int j, int k)
{
	if(k <= 0)
	{
		return false;
	}
	
	if(i < 0 || j < 0 || i >= m || j >= n)
	{
		return false;
	}
	
	if(i == n - 1 && j == m - 1)
	{
		ans = min(ans, k);
		return true;
	}
	
	if(dp[i][j][k] != -1)
	{
		return dp[i][j][k];
	}
	
	bool a = 0;
	
	a = a || find(v, n, m, i + 1, j, k - v[i][j]);
	a = a || find(v, n, m, i, j + 1, k - v[i][j]);
	a = a || find(v, n, m, i + 1, j + 1, k - v[i][j]);
	
	dp[i][j][k] = a;
	
	return a;
}

int main()
{
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			for(int k = 0; k < 100; k++)
				dp[i][j][k] = -1;
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<int> > v(n, vector<int>(m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cin >> v[i][j];
	}
	ans = k;
	
	cout << find(v, n, m, 0, 0, k) << endl;
	cout << k - ans;
}
