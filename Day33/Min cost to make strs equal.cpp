#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(string s1, string s2, int n1, int n2, int sum)
{
	if(n1 == 0 && n2 == 0)
	{
		ans = min(ans, sum);
		return ans;
	}
	
	if(n1 == 0)
	{
		for(int i = n2; i > 0; i--)
		{
			sum += (s2[i - 1] - '0');
		}
		ans = min(ans, sum);
		return ans;
	}
	
	if(n2 == 0)
	{
		for(int i = n1; i > 0; i--)
		{
			sum += (s1[i - 1] - '0');
		}
		ans = min(ans, sum);
		return ans;
	}
	
	if(dp[n1 - 1][n2 - 1] != -1)
	{
		return dp[n1 - 1][n2 - 1];
	}
	
	if(s1[n1 - 1] == s2[n2 - 1])
	{
		dp[n1 - 1][n2 - 1] = find(s1, s2, n1 - 1, n2 - 1, sum);
		return dp[n1 - 1][n2 - 1];
	}
	else
	{
		int a = INT_MAX;
		int b = find(s1, s2, n1 - 1, n2, sum + (s1[n1 - 1] - '0'));
		int c = find(s1, s2, n1, n2 - 1, sum + (s2[n2 - 1] - '0'));
		int d = find(s1, s2, n1 - 1, n2 - 1, sum + (s1[n1 - 1] - '0') + (s2[n2 - 1] - '0'));
		dp[n1 - 1][n2 - 1] = min(a, min(b, min(c, d)));
		return dp[n1 - 1][n2 - 1];
	}
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	
	cout << find(s1, s2, s1.length(), s2.length(), 0) << endl;
	cout << ans;
}
