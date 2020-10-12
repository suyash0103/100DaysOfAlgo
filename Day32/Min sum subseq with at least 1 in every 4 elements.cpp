#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	vector<int> dp(n);
	for(int i = 0; i < n; i++)
	{
		if(i < 4)
		{
			dp[i] = v[i];
		}
		else
		{
			dp[i] = min(dp[i - 1], min(dp[i - 2], min(dp[i - 3], dp[i - 4]))) + v[i];
		}
	}
	
	int ans = dp[n - 1];
	ans = min(ans, min(dp[n - 2], min(dp[n - 3], dp[n - 4])));
	
	cout << ans;
}
