#include<bits/stdc++.h>

using namespace std;

int ans = 1;

int main()
{
	string s;
	cin >> s;
	
	map<pair<int, int>, int> mpp;
	
	int i, j;
	
	if(s.length() % 2 == 0)
	{
		i = s.length()/2 - 1;
		j = s.length()/2 - 1;
	}
	else
	{
		i = s.length()/2;
		j = s.length()/2;
	}

	for(i = s.length() - 1; i >= 0; i--)
	{
		for(j = i; j < s.length(); j++)
		{
			if(i == j)
			{
				mpp[{i, j}] = 1;
				continue;
			}
			
			if(s[i] == s[j] && i == j - 1)
			{
				mpp[{i, j}] = 1;
				ans = max(ans, j - i + 1);
				continue;
			}
			
			if(s[i] != s[j])
			{
				mpp[{i, j}] = 0;
				continue;
			}
			
			if(s[i] == s[j] && mpp[{i + 1, j - 1}] == 1)
			{
				mpp[{i, j}] = 1;
				ans = max(ans, j - i + 1);
			}
			else
			{
				mpp[{i, j}] = 0;
			}
		}
	}
	
	cout << ans;
}














