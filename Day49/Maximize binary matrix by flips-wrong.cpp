#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int main()
{
	int r, c;
	cin >> r >> c;
	
	vector<vector<int> > v(r, vector<int>(c));
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			cin >> v[i][j];
		}
	}
	
	vector<vector<int> > ones(r, vector<int>(c, 0));
	ones[0][0] = v[0][0];
	for(int i = 1; i < c; i++)
	{
		if(v[0][i] == 1)
		{
			ones[0][i] = ones[0][i - 1] + 1;
		}
		else
		{
			ones[0][i] = 0;
		}
	}
	
	for(int i = 1; i < r; i++)
	{
		if(v[i][0] == 1)
		{
			ones[i][0] = ones[i - 1][0] + 1;
		}
		else
		{
			ones[i][0] = 0;
		}
	}
	
	for(int i = 1; i < r; i++)
	{
		for(int j = 1; j < c; j++)
		{
			ones[i][j] = ones[i - 1][j] + ones[i][j - 1] - ones[i - 1][j - 1] + v[i][j];
		}
	}
	
	int ans = 0;
	
	for(int k = 1; k <= min(r, c); k++)
	{
		for(int i = 0; i + k - 1 <= r; i++)
		{
			for(int j = 0; j + k - 1 <= c; j++)
			{
				ans = max(ans, ones[r - 1][c - 1] - )
			}
		}
	}
}








