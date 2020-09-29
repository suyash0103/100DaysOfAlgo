#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int dp[100][100][100];

int find(vector<vector<int> >& v, int i, int j, int m, int n, int sum, int req)
{
//	cout << i << " " << j << " " << sum << endl;
	if(i < 0 || j < 0 || i >= m || j >= n)
	{
		return 0;
	}
	
	if(i == m - 1 && j == n - 1)
	{
		sum += v[i][j];
		if(sum == req)
		{
			ans++;
			return 1;
		}
		return 0;
	}
	
	if(dp[i][j][sum] != -1)
	{
		cout << i << " " << j << " " << dp[i][j][sum] << endl;
		return dp[i][j][sum];
	}
	
	dp[i][j][sum] = find(v, i + 1, j, m, n, sum + v[i][j], req) + find(v, i, j + 1, m, n, sum + v[i][j], req);
	return dp[i][j][sum];
}

int main()
{
	int m, n;
	cin >> m >> n;
	
	vector<vector<int> > v(m, vector<int>(n));
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}
	
	int k;
	cin >> k;
	
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			for(int x = 0; x < 100; x++)
			{
				dp[i][j][x] = -1;
			}
		}
	}
	
	cout << find(v, 0, 0, m, n, 0, k) << endl;
	cout << ans << endl;
}
