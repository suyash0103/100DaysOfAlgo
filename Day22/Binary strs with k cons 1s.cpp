#include<bits/stdc++.h>

using namespace std;

int ans = 0;

set<string> st;

int dp[10][10][10];

int find(int n, int k, int prev, string s)
{	
	if(n < 0 || k < 0)
	{
		return 0;
	}
	
	if(k == 0 && n == 0)
	{
		cout << s << endl;
//		ans++;
		return 1;
	}
	
	if(dp[n][k][prev] != -1)
	{
		return dp[n][k][prev];
	}
	
	int a = 0;
	
	if(prev == 2 || prev == 0)
	{
		string ss = s;
		s.push_back('0');
		a += find(n - 1, k, 0, s);
		s = ss;
		s.push_back('1');
		a += find(n - 1, k, 1, s);
	}
	else if(prev == 1)
	{
		string ss = s;
		s.push_back('1');
		a += find(n - 1, k - 1, 1, s);
		s = ss;
		s.push_back('0');
		a += find(n - 1, k, 0, s);
	}
	
	dp[n][k][prev] = a;
	return a;
}
    
int main()
{
	int n, k;
	cin >> n >> k;
	
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			for(int k = 0; k < 10; k++)
				dp[i][j][k] = -1;
	
	
	
	cout << find(n, k, 2, "") << endl;
//	cout << ans;
}
