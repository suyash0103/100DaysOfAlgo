#include<bits/stdc++.h>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	
	vector<vector<int> > v(m, vector<int>(n));
	
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin >> v[i][j];
		
	vector<vector<pair<int, int> > > mat(m, vector<pair<int, int> >(n));
	
	mat[0][0] = {v[0][0], 0};
	for(int i = 1; i < n; i++)
	{
		int a = mat[0][i - 1].first + v[0][i] * pow(2, mat[0][i - 1].second + 1);
		int b = mat[0][i - 1].second + 1;
		mat[0][i].first = a;
		mat[0][i].second = b;
	}
	
	for(int i = 1; i < m; i++)
	{
		int a = mat[i - 1][0].first + v[i][0] * pow(2, mat[i - 1][0].second + 1);
		int b = mat[i - 1][0].second + 1;
		mat[i][0].first = a;
		mat[i][0].second = b;
	}
	
	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
		{
			int a1 = mat[i][j - 1].first + v[i][j] * pow(2, mat[i][j - 1].second + 1);
			int b1 = mat[i][j - 1].second + 1;
			
			int a2 = mat[i - 1][j].first + v[i][j] * pow(2, mat[i - 1][j].second + 1);
			int b2 = mat[i - 1][j].second + 1;
			
			if(a1 <= a2)
			{
				mat[i][j].first = a2;
				mat[i][j].second = b2;
			}
			else
			{
				mat[i][j].first = a1;
				mat[i][j].second = b1;
			}
		}
	}
	
	cout << mat[m - 1][n - 1].first << " " << mat[m - 1][n - 1].second;
}
