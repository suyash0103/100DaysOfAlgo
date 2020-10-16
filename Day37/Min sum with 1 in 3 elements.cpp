#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	vector<int> dp(n, 0);
	dp[0] = v[0];
	dp[1] = v[1];
	dp[2] = v[2];
	
	int ans = INT_MAX;
	
	for(int i = 3; i < n; i++)
	{
		dp[i] = dp[i - 3] + v[i];
	}
	
	ans = min(dp[n - 1], min(dp[n - 2], dp[n - 3]));
	
//	for(int i = 0; i < n; i++)
//	{
//		cout << dp[i] << " ";
//	}
//	cout << endl;
	
	cout << ans;
}
