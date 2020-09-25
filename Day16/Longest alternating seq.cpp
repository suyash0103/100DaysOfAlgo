#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
	vector<vector<int> > las(n, vector<int>(2, 1));
	
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(v[i] > v[j])
			{
				las[i][1] = max(las[i][1], las[j][0] + 1);
			}
			else
			{
				las[i][0] = max(las[i][0], las[j][1] + 1);
			}
		}
	}
	
	int ans = 1;
	for(int i = 0; i < n; i++)
	{
		ans = max(ans, max(las[i][0], las[i][1]));
	}
	
	cout << ans;
}
