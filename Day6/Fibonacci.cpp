#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll n; 
	cin >> n;
	
	vector<ll> dp(n + 1);
	dp[1] = 1;
	dp[2] = 1;
	
	for(int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	
	cout << dp[n];
}
