#include<bits/stdc++.h>

using namespace std;

int ansMax = 0;
int ansMin = INT_MAX;

vector<vector<vector<pair<int, int> > > > dp(100, vector<vector<pair<int, int> > > (100, vector<pair<int, int> >(100, {0, INT_MAX})));

pair<int, int> p;

pair<int, int> find(vector<int>& v, int i, int n, int m, int sum1, int sum2)
{
	if(n == 0 && m == 0)
	{
		if(sum1 * sum2 == 9)
		{
			cout << "Y";
		}
		ansMax = max(ansMax, sum1 * sum2);
		ansMin = min(ansMin, sum1 * sum2);
		
		return {ansMax, ansMin};
	}
	
	if(i == v.size())
	{
		return {0, INT_MAX};
	}
	
//	if(dp[i][n][m].first != 0 && dp[i][n][m].second != INT_MAX)
//	{
//		cout << i << " " << n << " " << m << dp[i][n][m].first << " " << dp[i][n][m].second << endl;
//		return dp[i][n][m];
//	}
	
	int a = 0;
	int b = INT_MAX;
	
	if(n > 0 && m > 0)
	{
		pair<int, int> p1 = find(v, i + 1, n - 1, m, sum1 + v[i], sum2);
		a = max(a, p1.first);
		b = min(b, p1.second);
		
		pair<int, int> p2 = find(v, i + 1, n, m - 1, sum1, sum2 + v[i]);
		a = max(a, p2.first);
		b = min(b, p2.second);
		
		dp[i][n][m].first = max(dp[i][n][m].first, a);
		dp[i][n][m].second = min(dp[i][n][m].second, b);
		
//		dp[i][n][m] = {a, b};
		return dp[i][n][m];
	}
	
	else if(n > 0)
	{
		pair<int, int> p1 = find(v, i + 1, n - 1, m, sum1 + v[i], sum2);
		a = max(a, p1.first);
		b = min(b, p1.second);
		
		dp[i][n][m].first = max(dp[i][n][m].first, a);
		dp[i][n][m].second = min(dp[i][n][m].second, b);
		
//		dp[i][n][m] = {a, b};
		return dp[i][n][m];
	}
	else
	{
		pair<int, int> p1 = find(v, i + 1, n, m - 1, sum1, sum2 + v[i]);
		a = max(a, p1.first);
		b = min(b, p1.second);
		
		dp[i][n][m].first = max(dp[i][n][m].first, a);
		dp[i][n][m].second = min(dp[i][n][m].second, b);
		
//		dp[i][n][m] = {a, b};
		return dp[i][n][m];
	}
}

int main()
{
	p.first = 0;
	p.second = INT_MAX;
	
	int n, m;
	cin >> n >> m;
	
	vector<int> v(n + m);
	
//	for(int i)
	
	for(int i = 0; i < n + m; i++)
		cin >> v[i];
	
	p = find(v, 0, n, m, 0, 0);
	cout << p.first << " " << p.second << endl;
	cout << ansMax << " " << ansMin;
}
