#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > dp(100, vector<int>(100, -1));

int find(int sum, vector<int> v, int i)
{
	if(sum < 0)
	{
		return 0;
	}
	
	if(sum == 0)
	{
		return 1;
	}
	
	if(i == v.size())
	{
		return 0;
	}
	
	if(dp[sum][i] != -1)
	{
		return dp[sum][i];
	}

	dp[sum][i] = find(sum, v, i + 1) || find(sum - v[i], v, i + 1);
	
	return dp[sum][i];
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	
	int sum = 0;
	
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	
	if(sum % 2 == 1)
	{
		cout << "false";
		return 1;
	}
	
	if(find(sum/2, v, 0))
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
	
}
