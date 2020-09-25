#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	
	map<pair<int, int>, int> mp;
	map<pair<int, int>, int> pa;
	
	for(int i = s.length(); i >= 0; i--)
	{
		for(int j = i; j < s.length(); j++)
		{
			if(i == j)
			{
				mp[{i, j}] = 1;
				pa[{i, j}] = 1;
			}
			else if(s[i] == s[j] && i == j - 1)
			{
				mp[{i, j}] = 3;
				pa[{i, j}] = 1;
			}
			else if(s[i] == s[j] && i < j - 1)
			{
				if(pa[{i + 1, j - 1}] == 0)
				{
					mp[{i, j}] = mp[{i + 1, j - 1}];
					pa[{i, j}] = 0;
				}
				else
				{
					mp[{i, j}] = mp[{i + 1, j - 1}] + 1 + mp[{i, i}] + mp[{j, j}];
					pa[{i, j}] = 1;
				}
			}
			else
			{
				mp[{i, j}] = mp[{i + 1, j - 1}];
				pa[{i, j}] = 0;
			}
		}
	}
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		int r1, r2;
		cin >> r1 >> r2;
		cout << mp[{r1, r2}] << endl;
	}
}
