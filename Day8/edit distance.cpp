#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int find(string s1, string s2, int n1, int n2)
{
	if(n1 == 0)
	{
		return n2;
	}
	
	if(n2 == 0)
	{
		return n1;
	}
	
	if(s1[n1 - 1] == s2[n2 - 1])
	{
		return find(s1, s2, n1 - 1, n2 - 1);
	}
	else
	{
		return 1 + min(min(find(s1, s2, n1 - 1, n2), find(s1, s2, n1, n2 - 1)), find(s1, s2, n1 - 1, n2 - 1));
	}
}

int main()
{
	int t = 100;
	while(t--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		
		int n1 = s1.length();
		int n2 = s2.length();
		
//		cout << find(s1, s2, s1.length(), s2.length()) << endl;
		
		vector<vector<int> > dp(n1 + 1, vector<int>(n2 + 1, 0));
		
		for(int i = 0; i <= n1; i++)
		{
			for(int j = 0; j <= n2; j++)
			{
				if(i == 0)
				{
					dp[i][j] = j;
				}
				
				else if(j == 0)
				{
					dp[i][j] = i;
				}
				
				else if(s1[i - 1] == s2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				
				else
				{
					dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
				}
			}
		}
		
		cout << dp[n1][n2] << endl;
	}
}
