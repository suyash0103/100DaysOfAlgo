#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int ans = 0;

vector<vector<int> > dpmemo(100, vector<int>(100, 0));
vector<vector<int> > dp(100, vector<int>(100, 0));

int find(vector<ll> v, int index, int n, int sum)
{
	if(sum == 0)
	{
		return 1;
	}
	
	if(sum < 0)
	{
		return 0;
	}
	
	if(index == n)
	{
		return 0;
	}
	
	if(dpmemo[index][sum] != 0)
	{
		return dpmemo[index][sum];
	}
	
	int a = 0, b = 0;
	
	if(v[index] <= sum)
		a = find(v, index, n, sum - v[index]);
	b = find(v, index + 1, n, sum);
	
	dpmemo[index][sum] = a + b;
	ans = max(ans, dpmemo[index][sum]);
	return dpmemo[index][sum];
}

int main()
{
	ll n;
	cin >> n;
	
	vector<ll> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
		
	ll N;
	cin >> N;
	
	find(v, 0, n, N);
	
	cout << "Memoised: " << ans << endl;
	
	dp[0][0] = 0;
	
	for(int i = 1; i <= N; i++)
	{
		dp[0][i] = 0;
	}
	
	for(int i = 1; i <= n; i++)
	{
		dp[i][0] = 1;
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(v[i - 1] <= j)
			{
				dp[i][j] += dp[i][j - v[i - 1]];
			}
			dp[i][j] += dp[i - 1][j];
		}
	}
	
	cout << "DP: " << dp[n][N];
}
