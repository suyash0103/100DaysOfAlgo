#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int dp[100][100][10];

int find(vector<vector<int> >& v, int m, int n, int i, int j, int coins, int dir)
{
	if(i < 0 || j < 0 || i >= m || j >= n)
	{
		return 0;
	}
	
	if(v[i][j] == -1)
	{
		ans = max(ans, coins);
		return coins;
	}
	
	if(dp[i][j][dir] != -1)
	{
		return dp[i][j][dir];
	}
	
	int a = 0;
	
	if(dir == 1)
	{
		a = max(a, find(v, m, n, i, j + 1, coins + v[i][j], dir));
		a = max(a, find(v, m, n, i + 1, j, coins + v[i][j], 0));
	}
	else
	{
		a = max(a, find(v, m, n, i, j - 1, coins + v[i][j], dir));
		a = max(a, find(v, m, n, i + 1, j, coins + v[i][j], 1));
	}
	
	dp[i][j][dir] = max(dp[i][j][dir], a);
	return a;
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
	
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			for(int k = 0; k < 10; k++)
				dp[i][j][k] = -1;
		}
	}
	
	cout << find(v, m, n, 0, 0, 0, 1) << endl;
	cout << ans;
}

//5
//5
//0 1 1 1 1
//1 -1 1 -1 0
//-1 1 1 -1 1
//1 0 0 1 0
//1 0 -1 1 0
