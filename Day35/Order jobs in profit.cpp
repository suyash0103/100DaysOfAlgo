#include<bits/stdc++.h>

using namespace std;

int ans = 0;

struct Node {
	int start;
	int end;
	int profit;
};

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(vector<Node>& v, int n, int i, int end, int sum)
{
	if(i >= n)
	{
		ans = max(ans, sum);
		dp[i][end] = ans;
		return ans;
	}
	
	if(dp[i][end] != -1)
	{
		return dp[i][end];
	}
	
	int a = 0;
	if(v[i].start >= end)
	{
		a = find(v, n, i + 1, v[i].end, sum + v[i].profit);
	}
	a = max(a, find(v, n, i + 1, end, sum));
	dp[i][end] = a;
	return a;
}

int main()
{
	int n;
	cin >> n;
	vector<Node> v(n);
	
	for(int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(Node());
		v[i].start = a;
		v[i].end = b;
		v[i].profit = c;
	}
	
	cout << find(v, n, 0, 0, 0) << endl;
	cout << ans;
}
