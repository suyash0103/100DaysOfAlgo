#include<bits/stdc++.h>

using namespace std;

int ans = 0;

set<int> cubes;

void makeCubes()
{
	int i = 1;
	while(true)
	{
		int p = pow(i, 3);
		if(p <= 5000000)
		{
			cubes.insert(p);
		}
		else
		{
			break;
		}
		i++;
	}
}

//vector<vector<int> > dp(100, vector<int>(100, -1));
int dp[100][100][100];

int find(vector<int>& v, int i, int sum, int k)
{
	if(k == 0)
	{
		if(cubes.find(sum) != cubes.end())
		{
			ans++;
			return 1;
		}
		return 0;
	}
	
	if(i == v.size())
	{
		return 0;
	}
	
	if(dp[i][k][sum] != -1)
	{
		return dp[i][k][sum];
	}
	
	dp[i][k][sum] = find(v, i + 1, sum, k) + find(v, i + 1, sum + v[i], k - 1);
	return dp[i][k][sum];
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
		
	makeCubes();
	
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			for(int k = 0; k < 100; k++)
				dp[i][j][k] = -1;
		}
	}
	
	cout << find(v, 0, 0, 3) << endl;
	cout << ans;
}
