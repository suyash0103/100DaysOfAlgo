#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int dp[100][100][100];

int checkZero(int num)
{
	int zero = 0;
	while(num % 10 == 0 && num > 0)
	{
		zero++;
		num = num / 10;
	}
	
	return zero;
}

int find(vector<int>& v, int i, int k, int prod)
{
	if(k == 0)
	{
		int zeros = checkZero(prod);
		ans = max(ans, zeros);
		return zeros;
	}
	
	if(i == v.size())
	{
		return -1;
	}
	
	if(dp[i][k][prod] != -1)
	{
		return dp[i][k][prod];
	}
	
	int a = -1;
	
	a = max(a, max(find(v, i + 1, k - 1, prod * v[i]), find(v, i + 1, k, prod)));
	dp[i][k][prod] = max(dp[i][k][prod], a);
	return a;
}

int main()
{
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			for(int k = 0; k < 100; k++)
				dp[i][j][k] = -1;
	
	int n, k;
	cin >> n >> k;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	cout << find(v, 0, k, 1) << endl;
//	cout << ans;
}
