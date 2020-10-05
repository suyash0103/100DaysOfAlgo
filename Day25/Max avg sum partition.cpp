#include<bits/stdc++.h>

using namespace std;

int ans = 0;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(vector<int>& v, vector<int>& pre, int i, int k, int sum, int avg)
{
//	cout << i << " " << k << " " << sum << " " << avg << endl;
	
	if(k == 0 && i < v.size())
	{
		for(int j = i; j < v.size(); j++)
		{
			sum += v[j];
		}
		avg += (sum / (v.size() - i));
		ans = max(ans, avg);
		return avg;
	}
	
	if(i == v.size())
	{
		return 0;
	}
	
	if(dp[i][k] != -1)
	{
		return dp[i][k];
	}
	
	int a = 0;
	
	for(int j = i; j < v.size(); j++)
	{
		sum += v[j];
		a = max(a, find(v, pre, j + 1, k - 1, 0, avg + (sum / (j - i + 1))));
	}
	
	dp[i][k] = a;
	return a;
}

int main()
{
	int n;
	cin >> n;
	
	int sum = 0;
	vector<int> v(n);
	vector<int> pre(n, 0);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
		if(i == 0)
		{
			pre[i] = v[i];
		}
		else
		{
			pre[i] = pre[i - 1] + v[i];
		}
	}
	
	int k;
	cin >> k;
	
	ans = sum / n;
	cout << find(v, pre, 0, k - 1, 0, 0) << endl;
	cout << ans;
}
