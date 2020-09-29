#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(vector<int>& v, int i, int w, int c)
{
	if(w < 0)
	{
		return INT_MAX;
	}
	
	if(w == 0)
	{
		ans = min(ans, c);
		return ans;
	}
	
	if(i == v.size())
	{
		return INT_MAX;
	}
	
	if(dp[i][w] != -1)
	{
		return dp[i][w];
	}
	
	int a = INT_MAX;
	
	for(int j = i; j < v.size(); j++)
	{
		a = min(a, find(v, j + 1, w, c));
		a = min(a, find(v, j, w - v[j], c + 1));
	}
	
	dp[i][w] = a;
	return a;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	int w;
	cin >> w;
	
	find(v, 0, w, 0);
	cout << ans;
}
