#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int dp[100][100][100][100];

int find(int p, int q, int r, int ch)
{
	if(p < 0 || q < 0 || r < 0)
	{
		return 0;
	}
	
	if(p == 0 && q == 0 && r == 0)
	{
		ans++;
		return 1;
	}
	
	if(p == 0 && q == 0 && ch == 2)
	{
		return 0;
	}
	
	if(p == 0 && r == 0 && ch == 1)
	{
		return 0;
	}
	
	if(q == 0 && r == 0 && ch == 0)
	{
		return 0;
	}
	
	if(dp[p][q][r][ch] != -1)
	{
		return dp[p][q][r][ch];
	}
	
	int a = 0;
	
	if(ch == 3)
	{
		a += find(p - 1, q, r, 0);
		a += find(p, q - 1, r, 1);
		a += find(p, q, r - 1, 2);
	}
	
	else if(ch == 0)
	{
		a += find(p, q - 1, r, 1);
		a += find(p, q, r - 1, 2);
	}
	
	else if(ch == 1)
	{
		a += find(p - 1, q, r, 0);
		a += find(p, q, r - 1, 2);
	}
	
	else if(ch == 2)
	{
		a += find(p - 1, q, r, 0);
		a += find(p, q - 1, r, 1);
	}
	
	dp[p][q][r][ch] = a;
	return a;
}

int main()
{
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			for(int k = 0; k < 100; k++)
			{
				for(int l = 0; l < 100; l++)
				{
					dp[i][j][k][l] = -1;
				}
			}
		}
	}
	
	int p, q, r;
	cin >> p >> q >> r;
	
	cout << find(p, q, r, 3) << endl;
	cout << ans;
}
