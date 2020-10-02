#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int dp[10][10][10][10];

int find(int n, string s, int a, int b, int c)
{
	if(b > 1)
	{
		return 0;
	}
	
	if(c > 2)
	{
		return 0;
	}
	
	if(n == 0)
	{
//		cout << s << endl;
		ans++;
		return 1;
	}
	
	if(dp[n][a][b][c] != -1)
	{
		return dp[n][a][b][c];
	}
	
	int aa = find(n - 1, s, a + 1, b, c) + find(n - 1, s, a, b + 1, c) + find(n - 1, s, a, b, c + 1);
	dp[n][a][b][c] = aa;
	return aa;
}

int main()
{
	int n;
	cin >> n;
	
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			for(int k = 0; k < 10; k++)
			{
				for(int l = 0; l < 10; l++)
				{
					dp[i][j][k][l] = -1;
				}
			}
		}
	}
	
	cout << find(n, "", 0, 0, 0) << endl;
	
}
