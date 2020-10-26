#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int dp[100][100][100];

int find(int n, set<int>& st, int open, int close, int i)
{
	if(open == close && open == n/2)
	{
//		ans++;
		return 1;
	}
	
	if(open > n/2 || close > n/2 || open < close)
	{
		return 0;
	}
	
	if(dp[open][close][i] != -1)
	{
		return dp[open][close][i];
	}
	
	int a = 0;
	
	if(st.find(i) != st.end())
	{
		a += find(n, st, open + 1, close, i + 1);
	}
	
	else
	{
		if(open != close)
		{
			a += find(n, st, open, close + 1, i + 1);
		}
		
		a += find(n, st, open + 1, close, i + 1);
	}
	
	dp[open][close][i] = a;
	return a;
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
	
	int n, s;
	cin >> n >> s;
	
	set<int> st;
	for(int i = 0; i < s; i++)
	{
		int a;
		cin >> a;
		st.insert(a);
	}
	
	cout << find(n, st, 0, 0, 0) << endl;
//	cout << ans;
}
