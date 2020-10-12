#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

int dp[100][100][100];

int find(string s1, string s2, int n1, int n2, int k, int sum)
{
	if(k == 0)
	{
//		cout << "A" << sum << endl;
		ans = min(ans, sum);
		return ans;
	}
	
	if(n1 == 0 || n2 == 0)
	{
		return INT_MAX;
	}
	
	if(dp[n1][n2][k] != -1)
	{
		return dp[n1][n2][k];
	}
	
	if(s1[n1 - 1] == s2[n2 - 1])
	{
		dp[n1][n2][k] = find(s1, s2, n1 - 1, n2 - 1, k - 1, sum);
		return dp[n1][n2][k];
	}
	else
	{
		int a = INT_MAX;
		int b = find(s1, s2, n1 - 1, n2, k, sum);
		int c = find(s1, s2, n1, n2 - 1, k, sum);
		int char1 = s1[n1 - 1] - '0';
		int char2 = s2[n2 - 1] - '0';
		int d = find(s1, s2, n1 - 1, n2 - 1, k - 1, sum + (char1 ^ char2));
		
		a = min(a, min(b, min(c, d)));
		dp[n1][n2][k] = a;
		return a;
	}
}

int main()
{
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
	
	string s1, s2;
	cin >> s1 >> s2;
	
	int k;
	cin >> k;
	
	cout << find(s1, s2, s1.length(), s2.length(), k, 0) << endl;
	cout << ans;
}





