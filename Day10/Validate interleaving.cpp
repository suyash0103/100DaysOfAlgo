#include<bits/stdc++.h>

using namespace std;

int dp[100][100][100];

int valid(string s1, string s2, string t, int ind1, int ind2, int testind)
{
	if(testind == t.length())
	{
		return 1;
	}
	
	if(ind1 == s1.length() && ind2 == s2.length())
	{
		return 0;
	}
	
	if(dp[ind1][ind2][testind] != -1)
	{
		return dp[ind1][ind2][testind];
	}
	
	if(ind1 == s1.length())
	{
		if(t[testind] == s2[ind2])
		{
			dp[ind1][ind2][testind] = valid(s1, s2, t, ind1, ind2 + 1, testind + 1);
			return dp[ind1][ind2][testind];
		}
		else
		{
			dp[ind1][ind2][testind] = valid(s1, s2, t, ind1, ind2 + 1, testind);
			return dp[ind1][ind2][testind];
		}
	}
	
	if(ind2 == s2.length())
	{
		if(t[testind] == s1[ind1])
		{
			dp[ind1][ind2][testind] = valid(s1, s2, t, ind1 + 1, ind2, testind + 1);
			return dp[ind1][ind2][testind];
		}
		else
		{
			dp[ind1][ind2][testind] = valid(s1, s2, t, ind1 + 1, ind2, testind);
			return dp[ind1][ind2][testind];
		}
	}
	
	if(s1[ind1] == t[testind] && s2[ind2] == t[testind])
	{
		dp[ind1][ind2][testind] = valid(s1, s2, t, ind1 + 1, ind2, testind + 1) || valid(s1, s2, t, ind1, ind2 + 1, testind + 1);
		return dp[ind1][ind2][testind];
	}
	
	else if(s1[ind1] == t[testind])
	{
		dp[ind1][ind2][testind] = valid(s1, s2, t, ind1 + 1, ind2, testind + 1);
		return dp[ind1][ind2][testind];
	}
	
	else if(s2[ind2] == t[testind])
	{
		dp[ind1][ind2][testind] = valid(s1, s2, t, ind1, ind2 + 1, testind + 1);
		return dp[ind1][ind2][testind];
	}
	
	else
	{
		dp[ind1][ind2][testind] = valid(s1, s2, t, ind1 + 1, ind2 + 1, testind) || valid(s1, s2, t, ind1, ind2 + 1, testind) || valid(s1, s2, t, ind1 + 1, ind2, testind);
		return dp[ind1][ind2][testind];
	}
}

int main()
{
	string s1, s2, t;
	
	cin >> s1 >> s2 >> t;
	
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			for(int k = 0; k < 100; k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}
	
	cout << valid(s1, s2, t, 0, 0, 0);
}
