#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

//int diag1 = 0;
//int diag2 = 0;

set<int> diag1;
set<int> diag2;

bool canInsert(vector<vector<int> >& v, int row, int col)
{
	int i = col - 1;
	int j = 0;
	
	while(i >= 0)
	{
		if(v[row][i] == 1)
			return false;
		i--;
	}
	
//	if(diag1.find(abs(row - col)) != diag1.end() || diag2.find(row + col) != diag2.end())
//	{
//		return false;
//	}
//	
//	return true;
	
//	if(row == col && diag1 == 1)
//		return false;
//	else if(row + col + 1 == v.size() && diag2 == 1)
//		return false;
//	return true;
	
	i = col - 1;
	j = row - 1;
	
	while(i >= 0 && j >= 0)
	{
		if(v[j][i] == 1)
			return false;
		i--;
		j--;
	}
	
	i = row + 1;
	j = col - 1;
	while(i < v.size() && j >= 0)
	{
		if(v[i][j] == 1)
			return false;
		i++;
		j--;
	}

	return true;
}

bool fill(vector<vector<int> >& v, int row, int col)
{
	if(col == row)
	{
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < row; j++)
				cout << v[i][j] << " ";
			cout << endl;
		}
		return true;
	}
		
	for(int i = 0; i < row; i++)
	{
		if(canInsert(v, i, col))
		{
			v[i][col] = 1;
//			diag1.insert(abs(i - col));
//			diag2.insert(i + col);
			
			if(fill(v, row, col + 1) == true)
			{
				return true;
			}
			v[i][col] = 0;
//			diag1.erase(abs(i - col));
//			diag2.erase(i + col);
		}
	}
	
	return false;
}

int main()
{
	ll n;
	cin >> n;
	
	vector<vector<int> > v(n, vector<int>(n, 0));
	
	cout << fill(v, n, 0);
}
