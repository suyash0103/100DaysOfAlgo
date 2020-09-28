#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

vector<vector<int> > dp(100, vector<int>(100, INT_MAX));

map<pair<int, int>, int> mp;

int find(vector<int>& v, int i, int k, int sum, int prev)
{
//	cout << i << " " << k << endl;
	if(k == 0)
	{
		ans = min(ans, sum);
		return ans;
	}
	
	if(i < 0)
	{
		return INT_MAX;
	}
	
//	if(mp.find({i, k}) != mp.end())
//	{
//		return mp[{i, k}];
//	}
	
	int a = INT_MAX;
	if(v[i] <= prev)
	{
		a = min(a, find(v, i - 1, k - 1, sum + v[i], v[i]));
	}
	a = min(a, find(v, i - 1, k, sum, prev));
	dp[i][k] = min(dp[i][k], a);
	mp[{i, k}] = a;
	return a;
//	return dp[i][k];
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	int k;
	cin >> k;
	
	cout << find(v, n - 1, k, 0, INT_MAX) << endl;
	cout << ans << endl;
	
//	for(int i = 0; i <= n; i++)
//	{
//		for(int j = 0; j <= k; j++)
//		{
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
}

//10
//58 12 11 12 82 30 20 77 16 86
//3
