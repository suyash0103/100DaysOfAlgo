#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(vector<vector<int> >& g, int u, int v, int k, int sum)
{
	cout << u << " " << k << " " << sum << endl;
	
	if(u == v && k == 0)
	{
		ans = min(ans, sum);
		return sum;
	}
	
	if(k == 0)
	{
		return INT_MAX;
	}
	
	if(dp[u][k] != -1)
	{
		return dp[u][k];
	}
	
	int a = INT_MAX;
	
	for(int i = 0; i < g.size(); i++)
	{
		if(g[u][i] != -1)
		{
			a = min(a, find(g, i, v, k - 1, sum + g[u][i]));
		}
	}
	
	dp[u][k] = a;
	return a;
}

int main()
{
	int n, e;
	cin >> n >> e;
	
	vector<vector<int> > g(n + 1, vector<int>(n + 1, -1));
	for(int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		g[a][b] = c;
	}
	
	int u, v, k;
	cin >> u >> v >> k;
	
	cout << find(g, u, v, k, 0) << endl;
	cout << ans;
}
