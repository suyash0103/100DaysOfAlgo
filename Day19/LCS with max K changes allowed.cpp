#include<bits/stdc++.h>

using namespace std;

int dp[100][100][100];

int lcs(string s1, string s2, int k, int i, int j)
{
	if(i == s1.length() || j == s2.length())
	{
		return 0;
	}
	
	if(dp[i][j][k] != -1)
	{
		return dp[i][j][k];
	}
	
	if(s1[i] == s2[j])
	{
		dp[i][j][k] = 1 + lcs(s1, s2, k, i + 1, j + 1);
		return dp[i][j][k];
	}
	else
	{
		if(k > 0)
		{
			int a = 1 + lcs(s1, s2, k - 1, i + 1, j + 1);
			int b = max(lcs(s1, s2, k, i + 1, j), lcs(s1, s2, k, i, j + 1));
			dp[i][j][k] = max(a, b);
			return dp[i][j][k];
		}
		else
		{
			dp[i][j][k] = max(lcs(s1, s2, k, i + 1, j), lcs(s1, s2, k, i, j + 1));
			return dp[i][j][k];
		}
	}
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	
	int k;
	cin >> k;
	
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			for(int kk = 0; kk < 100; kk++)
				dp[i][j][kk] = -1;
	
	cout << lcs(s1, s2, k, 0, 0);
}
