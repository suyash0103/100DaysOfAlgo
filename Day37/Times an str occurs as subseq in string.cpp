#include<bits/stdc++.h>

using namespace std;

int ans = 0;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(string s1, string s2, int i, int j)
{
	cout << i << " " << j << endl;
	if(j == s2.length())
	{
		ans++;
		return 1;
	}
	
	if(i == s1.length())
	{
		return 0;
	}
	
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	
	int t = 0;
	
	if(s1[i] == s2[j])
	{
		t += find(s1, s2, i + 1, j + 1);
	}
	t += find(s1, s2, i + 1, j);
	
	return t;
	
	dp[i][j] = t;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	
	cout << find(s1, s2, 0, 0) << endl;
	cout << ans;
}
