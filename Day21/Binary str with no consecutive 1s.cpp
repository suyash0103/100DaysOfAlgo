#include<bits/stdc++.h>

using namespace std;

int ans = 0;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(int n, int i, int prev)
{
	if(i == n)
	{
//		ans++;
		return 1;
	}
	
	if(dp[i][prev] != -1)
	{
		return dp[i][prev];
	}
	
	int a = 0;
	
	if(prev == 2 || prev == 0)
	{
		a = find(n, i + 1, 0) + find(n, i + 1, 1);
	}
	else
	{
		a = find(n, i + 1, 0);
	}
	
	dp[i][prev] = a;
	return a;
}

int main()
{
	int n;
	cin >> n;
	
	cout << find(n, 0, 2) << endl;
//	cout << ans;
}
