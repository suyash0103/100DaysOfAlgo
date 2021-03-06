#include<bits/stdc++.h>

using namespace std;

int ans = 0;
vector<vector<int> > g(10);

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(int n, int prev)
{
	if(n == 0)
	{
		ans++;
		return 1;
	}
	
	if(dp[n][prev] != -1)
	{
		return dp[n][prev];
	}
	
	int a = 0;
	
	for(int i = 0; i < g[prev].size(); i++)
	{
//		st.insert(g[prev][i]);
		a += find(n - 1, g[prev][i]);
//		st.erase(g[prev][i]);
	}
	
	dp[n][prev] = a;
	
	return a;
}

int main()
{
	g[0].push_back(8);
	g[1].push_back(2);
	g[1].push_back(4);
	g[2].push_back(1);
	g[2].push_back(3);
	g[2].push_back(5);
	g[3].push_back(6);
	g[3].push_back(2);
	g[4].push_back(1);
	g[4].push_back(5);
	g[4].push_back(7);
	g[5].push_back(2);
	g[5].push_back(4);
	g[5].push_back(6);
	g[5].push_back(8);
	g[6].push_back(3);
	g[6].push_back(9);
	g[6].push_back(5);
	g[7].push_back(8);
	g[7].push_back(4);
	g[8].push_back(5);
	g[8].push_back(0);
	g[8].push_back(7);
	g[8].push_back(9);
	g[9].push_back(8);
	g[9].push_back(6);
	
	
	
	int n;
	cin >> n;
	
	int a = 0;
	for(int i = 0; i <= 9; i++)
	{
		set<int> st;
		st.insert(i);
		int c = find(n - 1, i);
		cout << i << ": " << c << endl;
		a += c;
		st.erase(i);
	}
	
	cout << a << endl;
	cout << ans;
}
