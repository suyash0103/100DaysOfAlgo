#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int dp[100][100][100];

int dfs(vector<vector<int> >& g, vector<int>& vis, int s, int d, int k)
{
	if(vis[s] == 1)
	{
		return 0;
	}
	
	if(k == 0 && s == d)
	{
		ans++;
		return 1;
	}
	
	if(s == d && k != 0)
	{
		return 0;
	}
	
	if(dp[s][d][k] != -1)
	{
		return dp[s][d][k];
	}
	
	int a = 0;
	
	vis[s] = 1;
	
	for(int i = 0; i < g[s].size(); i++)
	{
		if(vis[g[s][i]] == -1)
		{
			a += dfs(g, vis, g[s][i], d, k - 1);
		}
	}
	
	vis[s] = -1;
	dp[s][d][k] = a;
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
	
	int n, e;
	cin >> n >> e;
	
	vector<vector<int> > g(n);
	
	for(int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		
		g[u].push_back(v);
	}
	
	int k;
	cin >> k;
	vector<int> vis(n, -1);
	int dest;
	cin >> dest;
	cout << dfs(g, vis, 0, dest, k) << endl;
//	cout << ans;
}

