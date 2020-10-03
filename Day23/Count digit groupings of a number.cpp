#include<bits/stdc++.h>

using namespace std;

int ans = 0;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(string s, int i, int prev)
{
	if(i == s.length())
	{
//		ans++;
		return 1;
	}
	
	int sum = 0;
	
	int t = 0;
	
	if(dp[i][prev] != -1)
	{
		return dp[i][prev];
	}
	
	for(int j = i; j < s.length(); j++)
	{
		int a = s[j] - '0';
		sum += a;
		if(sum >= prev)
		{
			t += find(s, j + 1, sum);
		}
	}
	
	dp[i][prev] = t;
	return t;
}

int main()
{
	string s;
	cin >> s;
	
	cout << find(s, 0, 0) << endl;
//	cout << ans;
}
