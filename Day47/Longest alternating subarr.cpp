#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	vector<int> dp(n, 1);
	
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
	for(int i = n - 2; i >= 0; i--)
	{
		if(v[i] != v[i + 1])
		{
			dp[i] = dp[i + 1] + 1;
		}
		else
		{
			dp[i] = 1;
		}
	}
	
	for(int i = 0; i < n; i++)
		cout << dp[i] << " ";
}
