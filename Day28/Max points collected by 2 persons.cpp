#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int dp[10][10][10][10][10];

int dfs(vector<vector<int> >& v, int m, int n, int i1, int j1, int i2, int j2, int sum, int meets)
{
	if(i1 == m - 1 && j1 == n - 1 && i2 == 0 && j2 == n - 1)
	{
		ans = max(ans, sum);
		return sum;
	}
	
	if(i1 >= m || j1 >= n || i2 >= m || j2 >= n || i1 < 0 || j1 < 0 || i2 < 0 || j2 < 0)
	{
		return -1;
	}
	
	if(dp[i1][j1][i2][j2][meets] != -1)
	{
		return dp[i1][j1][i2][j2][meets];
	}
	
	int a = -1;
	
	if(i1 == i2 && j1 == j2)
	{
		if(meets == 0)
		{
			int b = dfs(v, m, n, i1 + 1, j1, i2 - 1, j2, sum, meets + 1);
			int c = dfs(v, m, n, i1, j1 + 1, i2 - 1, j2, sum, meets + 1);
			int d = dfs(v, m, n, i1 + 1, j1, i2, j2 + 1, sum, meets + 1);
			int e = dfs(v, m, n, i1, j1 + 1, i2, j2 + 1, sum, meets + 1);
			a = max(a, max(b, max(c, max(d, e))));
		}
		else
		{
			return -1;
		}
	}
	
	int b = dfs(v, m, n, i1 + 1, j1, i2 - 1, j2, sum + v[i1][j1] + v[i2][j2], meets);
	int c = dfs(v, m, n, i1, j1 + 1, i2 - 1, j2, sum + v[i1][j1] + v[i2][j2], meets);
	int d = dfs(v, m, n, i1 + 1, j1, i2, j2 + 1, sum + v[i1][j1] + v[i2][j2], meets);
	int e = dfs(v, m, n, i1, j1 + 1, i2, j2 + 1, sum + v[i1][j1] + v[i2][j2], meets);
	
	a = max(a, max(b, max(c, max(d, e))));
	dp[i1][j1][i2][j2][meets] = max(dp[i1][j1][i2][j2][meets], a);
	return a;
}

int main()
{
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			for(int k = 0; k < 10; k++)
				for(int l = 0; l < 10; l++)
					for(int m = 0; m < 10; m++)
						dp[i][j][k][l][m] = -1;
	
	int m, n;
	cin >> m >> n;
	
	vector<vector<int> > v(m, vector<int>(n));
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin >> v[i][j];
	
	cout << dfs(v, m, n, 0, 0, m - 1, 0, 0, 0) << endl;
	cout << ans;
}
