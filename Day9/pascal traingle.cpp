#include<bits/stdc++.h>

using namespace std;

int main()
{
	int m;
	cin >> m;
	
	cout << endl << endl;
	
	vector<vector<int> > v(m, vector<int>(m, 0));
	
	v[0][0] = 1;
	v[1][0] = 1;
	v[1][1] = 1;
	
	for(int i = 2; i < m; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			if(j == 0 || j == i)
			{
				v[i][j] = 1;
			}
			else
			{
				v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
			}
		}
	}
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
