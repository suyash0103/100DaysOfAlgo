#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

//vector<vector<int> > dp(100, vector<int>(100, INT_MAX));
//
//int find(string s1, string s2, int i, int j, int x, int y, int sum)
//{
//	cout << i << " " << j << " " << sum << endl;
//	
//	if(dp[i][j] != INT_MAX)
//	{
//		dp[i][j] = min(dp[i][j], sum);
//	}
//	
////	dp[i][j] = min(dp[i][j], sum);
//	
//	if(i == 0 && j == 0)
//	{
//		ans = min(ans, sum);
//		dp[i][j] = min(dp[i][j], sum);
//		return sum;
//	}
//	
//	if(i == 0)
//	{
//		sum += (j + 1) * y;
//		ans = min(ans, sum);
//		dp[i][j] = min(dp[i][j], sum);
//		return sum;
//	}
//	
//	if(j == 0)
//	{
//		sum += (i + 1) * x;
//		ans = min(ans, sum);
//		dp[i][j] = min(dp[i][j], sum);
//		return sum;
//	}
//	
//	if(dp[i][j] != INT_MAX)
//	{
////		dp[i][j] = min(dp[i][j], sum);
//		return dp[i][j];
//	}
//	
//	int a = INT_MAX;
//	
//	if(s1[i - 1] == s2[j - 1])
//	{
//		a = min(a, find(s1, s2, i - 1, j - 1, x, y, sum));
//	}
//	else
//	{
//		a = min(a, find(s1, s2, i - 1, j - 1, x, y, sum + x + y));
//		a = min(a, find(s1, s2, i - 1, j, x, y, sum + x));
//		a = min(a, find(s1, s2, i, j - 1, x, y, sum + y));
//	}
//	
//	dp[i][j] = min(dp[i][j], a);
//	return a;
//}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	
	int x, y;
	cin >> x >> y;
	
	int dp[s1.length()][s2.length()];
	
	dp[0][0] = 0;
	
	for(int i = 1; i <= s1.length(); i++)
	{
		dp[i][0] = dp[i - 1][0] + x;
	}
	
	for(int i = 1; i <= s2.length(); i++)
	{
		dp[0][i] = dp[0][i - 1] + y;
	}
	
	for(int i = 1; i <= s1.length(); i++)
	{
		for(int j = 1; j <= s2.length(); j++)
		{
			if(s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j] + x, min(dp[i][j - 1] + y, dp[i - 1][j - 1] + x + y));
			}
		}
	}
	
	for(int i = 0; i <= s1.length(); i++)
	{
		for(int j = 0; j <= s2.length(); j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << dp[s1.length()][s2.length()];
	
//	cout << find(s1, s2, s1.length(), s2.length(), x, y, 0) << endl;
//	cout << ans;
}

//abcd
//acdb
//10
//20
