#include<bits/stdc++.h>

using namespace std;

int ans = 0;

vector<vector<int> > dp(100, vector<int>(100, -1));

bool check(vector<int> v, int left, int right)
{
	int minE = v[left];
	int maxE = v[left];
	for(int i = left; i <= right; i++)
	{
		minE = min(minE, v[i]);
		maxE = max(maxE, v[i]);
	}
	
	if(minE * 2 > maxE)
		return true;
	return false;
}

int find(vector<int>& v, int left, int right)
{
	if(left > right)
	{
		return -1;
	}
	
	if(left == right)
	{
		ans = max(ans, 1);
		return 1;
	}
	
	if(check(v, left, right))
	{
		ans = max(ans, right - left + 1);
		return right - left + 1;
	}
	
	if(dp[left][right] != -1)
	{
		return dp[left][right];
	}
	
	int a = 0;
	
	a = max(a, find(v, left + 1, right));
	a = max(a, find(v, left, right - 1));
	
	dp[left][right] = a;
	
	return a;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
//	if(ans == n)
//		ans = n - 1;
	cout << n - find(v, 0, n - 1) << endl;
	cout << n - ans;
}
