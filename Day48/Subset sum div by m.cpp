#include<bits/stdc++.h>

using namespace std;

int ans = 0;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(vector<int>& v, int n, int m, int i, int sum)
{
	if(sum % m == 0 && sum != 0)
	{
		ans = 1;
		return 1;
	}
	
	if(i == n)
	{
		return 0;
	}
	
	if(dp[i][sum] != -1)
	{
		return dp[i][sum];
	}
	
	int a = 0;
	
	a = a || find(v, n, m, i + 1, sum + v[i]);
	a = a || find(v, n, m, i + 1, sum);
	
	dp[i][sum] = a;
	return a;
}

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	cout << find(v, n, m, 0, 0) << endl;
	cout << ans;
}
