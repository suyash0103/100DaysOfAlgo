#include<bits/stdc++.h>

using namespace std;

bool isPal(string s)
{
	int i = 0;
	int j = s.length() - 1;
	
	while(i <= j)
	{
		if(s[i] != s[j])
		{
			return false;
		}
		i++;
		j--;
	}
	
	return true;
}

int main()
{
	string s;
	cin >> s;
	
	vector<vector<int> > dp(s.length(), vector<int>(s.length(), INT_MAX));	
	
	for(int i = s.length() - 1; i >= 0; i--)
	{
		for(int j = 0; j < s.length(); j++)
		{
			if(i == j)
			{
				dp[i][j] = 0;
			}
			else if(i > j)
			{
				continue;
			}
			else
			{
				string sub = s.substr(i, j - i + 1);
//				cout << sub << " " << i << " " << j << endl;
				if(isPal(sub))
				{
					dp[i][j] = 0;
				}
				else
				{
					if(sub.length() == 2)
					{
						dp[i][j] = 1;
					}
					else
					{
						int val = INT_MAX;
						for(int k = i; k < j; k++)
						{
							val = min(val, 1 + dp[i][k] + dp[k + 1][j]);
						}
						dp[i][j] = val;	
					}
				}
			}
		}
	}
	
	cout << dp[0][s.length() - 1];
	
}
