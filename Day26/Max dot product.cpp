#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int dp[100][100];

int find(int i, int j, int zero, vector<int>& a, vector<int>& b, int sum)
{
	cout << i << " " << j << " " << sum << endl;
	if(i == 0 && j == 0)
	{
		ans = max(ans, sum);
		dp[i][j] = max(dp[i][j], ans);
		return sum;
	}
	
	if(j == 0)
	{
		ans = max(ans, sum);
		dp[i][j] = max(dp[i][j], ans);
		return sum;
	}
	
//	if(dp[i][j] != -1)
//	{
//		return max(dp[i][j], sum);
//	}
	
	int aa = -1;
	
	if(i > j)
	{
		aa = max(aa, find(i - 1, j, zero, a, b, sum));
	}
	
	aa = max(aa, find(i - 1, j - 1, zero, a, b, sum + a[i - 1] * b[j - 1]));
	dp[i][j] = max(dp[i][j], aa);
	return aa;
}

int main()
{
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			dp[i][j] = -1;
	
	int m, n;
	cin >> m >> n;
	
	vector<int> a(m);
	vector<int> b(n);
	
	for(int i = 0; i < m; i++)
		cin >> a[i];
	
	for(int i = 0; i < n; i++)
		cin >> b[i];
	
	cout << find(m, n, m - n, a, b, 0) << endl;
	cout << ans;
}

//5
//3
//2 3 1 7 8
//3 6 7
