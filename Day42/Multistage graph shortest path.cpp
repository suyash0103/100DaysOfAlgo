#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;
vector<int> g[100];
map<pair<int, int>, int> wt;

int find(int st, int end, int sum)
{
	if(st == end)
	{
		ans = min(ans, sum);
		return sum;
	}
	
	int a = INT_MAX;
	
	for(int i = 0; i < g[st].size(); i++)
	{
		a = min(a, find(g[st][i], end, sum + wt[{st, g[st][i]}]));
	}
	
	return a;
}

int main()
{
	int n, e;
	cin >> n >> e;
	
	for(int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		g[a].push_back(b);
		wt[{a, b}] = c;
	}
	
	cout << find(0, n - 1, 0) << endl;
	cout << ans;
}
