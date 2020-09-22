#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<vector<int> > v(n, vector<int>(n, 0));
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			cin >> v[i - 1][j - 1];
		}
	}
	
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			if(j == 0)
			{
				v[i][j] += v[i - 1][j];
			}
			else if(j == i)
			{
				v[i][j] += v[i - 1][j - 1];
			}
			else
			{
				v[i][j] += min(v[i - 1][j], v[i - 1][j - 1]);
			}
		}
	}
	
	for(int i = 0; i < n; i++)
		cout << v[n - 1][i] << " ";
}
