#include<bits/stdc++.h>

using namespace std;

int ans = 0;

vector<vector<int> > dp(100, vector<int>(100, -1));

bool find(vector<vector<int> >& v, int i, int j, int m, int n)
{
	if(i < 0 || j < 0 || i >= m || j >= n)
	{
		return false;
	}
	
	if(v[i][j] == -1)
	{
		return false;
	}
	
	if(i == m - 1 && j == n - 1)
	{
		ans = 1;
		return true;
	}
	
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	
	bool a = false;
	
	a = a || find(v, i + 1, j, m, n);
	a = a || find(v, i, j + 1, m, n);
	
	dp[i][j] = a;
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
	
	cout << find(v, 0, 0, m, n) << endl;
	cout << ans;
}
