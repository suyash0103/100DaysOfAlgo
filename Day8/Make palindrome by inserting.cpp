#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(string s, int n, int start, int end)
{
	if(start > end)
	{
		return 0;
	}
	
	if(start == end)
	{
		return 0;
	}
	
	if(dp[start][end] != -1)
	{
		return dp[start][end];
	}
	
	if(s[start] == s[end])
	{
		int a = find(s, n, start + 1, end - 1);
		dp[start][end] = a;
		return a;
	}
	else
	{
		int a = 1 + min(find(s, n, start + 1, end), find(s, n, start, end - 1));
		dp[start][end] = a;
		return a;
	}
}

int main()
{
	int t = 100;
	while(t--)
	{
		vector<vector<int> > dpp(100, vector<int>(100, -1));
		dp = dpp;
		string s;
		cin >> s;
		
		cout << find(s, s.length(), 0, s.length() - 1) << endl;
		
		vector<vector<int> > mem(100, vector<int>(100, 0));
		for(int i = s.length() - 1; i >= 0; i--)
		{
			for(int j = 0; j < s.length(); j++)
			{
				if(i > j)
				{
					mem[i][j] = 0;
					continue;
				}
				
				if(i == j)
				{
					mem[i][j] = 0;
					continue;
				}
				
				if(s[i] == s[j])
				{
					mem[i][j] = mem[i + 1][j - 1];
				}
				else
				{
					mem[i][j] = 1 + min(mem[i + 1][j], mem[i][j - 1]);
				}
			}
		}
		
		for(int i = 0; i <= s.length(); i++)
		{
			for(int j = 0; j <= s.length(); j++)
				cout << mem[i][j] << " ";
			cout << endl;
		}
		
	}
}
