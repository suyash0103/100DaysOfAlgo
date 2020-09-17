#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int ans = 0;

vector<vector<ll> > memo(100, vector<ll>(100, -1));

int find(ll m, ll n)
{
	if(m < 0 || n < 0)
	{
		return 0;
	}
	
	if(m == 0 && n == 0)
	{
		return 1;
	}
	
	if(memo[m][n] != -1)
	{
		return memo[m][n];
	}
	
	memo[m][n] =  find(m - 1, n) + find(m - 2, n) + find(m - 3, n) +
			find(m, n - 1) + find(m, n - 2) + find(m, n - 3);
			
	return memo[m][n];
}

int main()
{
	ll m, n;
	cin >> m >> n;
	
	cout << find(m, n);
}
