#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(vector<vector<int> >& v, int i, int j, int sum)
{
	if(j == v[0].size())
	{
		ans = min(ans, sum);
		return sum;
	}
	
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	
	int a = INT_MAX;
	
	for(int k = j; k < v[0].size(); k++)
	{
//		cout << i << " " << j << endl;
		a = min(a, find(v, k, k + 1, sum + v[i][k]));
	}
	
	dp[i][j] = a;
	return a;
}

int main()
{
	int n;
	cin >> n;
	
	vector<vector<int> > v(n, vector<int>(n, 0));
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j)
			{
				v[i][j] = 0;
			}
			else if(j < i)
			{
				v[i][j] = INT_MIN;
			}
			else
			{
				cin >> v[i][j];
			}
		}
	}
	
	cout << find(v, 0, 1, 0) << endl;
	cout << ans;
}
