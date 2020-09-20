#include<bits/stdc++.h>

using namespace std;

int dp[100][100][100];

int find(vector<vector<char> > v, int m, int n, string s, int i, int j, int t, vector<vector<int> > vis)
{
//	cout << i << " " << j << " " << t << endl;
	
	if(t == s.length())
	{
		return 1;
	}
	
	if(i < 0 || j < 0 || i >= m || j >= n)
	{
		return 0;
	}
	
	if(vis[i][j] == 1)
	{
		return 0;
	}
	
	vis[i][j] = 1;
	
	if(dp[i][j][t] != -1)
	{
		return dp[i][j][t];
	}
	
	if(s[t] == v[i][j])
	{
		dp[i][j][t] = find(v, m, n, s, i + 1, j, t + 1, vis) || find(v, m, n, s, i - 1, j, t + 1, vis) || find(v, m, n, s, i, j + 1, t + 1, vis) || find(v, m, n, s, i, j - 1, t + 1, vis);
		return dp[i][j][t];
	}
	
	dp[i][j][t] = find(v, m, n, s, i + 1, j, t, vis) || find(v, m, n, s, i - 1, j, t, vis) || find(v, m, n, s, i, j + 1, t, vis) || find(v, m, n, s, i, j - 1, t, vis);
	return dp[i][j][t];
}

int main()
{
	int m, n;
	cin >> m >> n;
	
	vector<vector<char> > v(m, vector<char>(n, 'a'));
	
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin >> v[i][j];
			
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
			
	vector<vector<int> > vis(m, vector<int>(n, 0));
	
	string s;
	cin >> s;
	
	cout << find(v, m, n, s, 0, 0, 0, vis);
}
