#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

int dp[100][100][100];

int diff(vector<int> v, int i, int j)
{
	int minE = v[i];
	int maxE = v[i];
	for(int x = i; x <= j; x++)
	{
		minE = min(minE, v[x]);
		maxE = max(maxE, v[x]);
	}
	
	return pow(maxE - minE, 2);
}

int find(vector<int>& v, int k, int i, int j, int sum)
{
	if(k == 1)
	{
		sum += diff(v, i, v.size() - 1);
		ans = min(ans, sum);
		return ans;
	}
	
	if(j >= v.size())
	{
		return INT_MAX;
	}
	
	if(dp[i][j][k] != INT_MAX)
	{
		return dp[i][j][k];
	}
	
	int a = INT_MAX;
	
	a = min(a, find(v, k, i, j + 1, sum));
	sum += diff(v, i, j);
	a = min(a, find(v, k - 1, j + 1, j + 1, sum));
	
	dp[i][j][k] = a;
	return a;
}

int main()
{
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			for(int k = 0; k < 100; k++)
				dp[i][j][k] = INT_MAX;
	
	int n, k;
	cin >> n >> k;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
		
//	sort(v.begin(), v.end());
	
	cout << find(v, k, 0, 0, 0) << endl;
	cout << ans;
}
