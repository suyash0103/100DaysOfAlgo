#include<bits/stdc++.h>

using namespace std;

int ansDel = INT_MAX;
int ansIns = INT_MAX;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	
	int dp[s1.length()][s2.length()];
	
	for(int i = 0; i <= s1.length(); i++)
	{
		for(int j = 0; j <= s2.length(); j++)
		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else
			{
				if(s1[i - 1] == s2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
	}
	
	cout << dp[s1.length()][s2.length()] << endl;
	
	int ins = s1.length() - dp[s1.length()][s2.length()];
	int del = s2.length() - dp[s1.length()][s2.length()];
	
	cout << ins << " " << del;
}
