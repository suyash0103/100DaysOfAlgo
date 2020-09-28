#include<bits/stdc++.h>

using namespace std;

set<string> st;

void find(vector<vector<int> >& dp, int i, int j, string s, string s1, string s2)
{
	if(i == 0 || j == 0)
	{
		if(s.length() == dp[s1.length()][s2.length()])
		{
			reverse(s.begin(), s.end());
			if(st.find(s) == st.end())
			{
				cout << s << endl;
				st.insert(s);
			}
		}
		return;
	}
	
	if(dp[i][j] == dp[i - 1][j - 1] + 1 && s1[i - 1] == s2[j - 1])
	{
		s.push_back(s1[i - 1]);
		find(dp, i - 1, j - 1, s, s1, s2);
	}
	else
	{
		find(dp, i - 1, j, s, s1, s2);
		find(dp, i, j - 1, s, s1, s2);
	}
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	
	int n1 = s1.length();
	int n2 = s2.length();
	
	vector<vector<int> > dp(n1 + 1, vector<int>(n2 + 1));
	for(int i = 0; i <= n1; i++)
	{
		for(int j = 0; j <= n2; j++)
		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
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
	
	cout << dp[n1][n2] << endl;
	
	string s = "";
	find(dp, n1, n2, s, s1, s2);
}










