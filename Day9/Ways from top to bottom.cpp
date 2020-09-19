#include<bits/stdc++.h>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	
	vector<vector<int> > v(m, vector<int>(n, 0));
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == 0 || j == 0)
			{
				v[i][j] = 1;
			}
			else
			{
				v[i][j] += v[i - 1][j] + v[i][j - 1];
			}
		}
	}
	
	cout << v[m - 1][n - 1];
}
