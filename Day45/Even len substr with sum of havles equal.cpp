#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	
//	vector<vector<int> > dp()
	int ans = 0;
	map<int, set<pair<int, int> > > mp;
	map<pair<int, int>, int> m;
	
	for(int i = 0; i < s.length(); i++)
	{
		int sum = s[i] - '0';
		if(i > 0 && s[i] == s[i - 1])
		{
			ans = max(ans, 2);
		}
		
		m[{i, i}] = 1;
		
		for(int j = i + 1; j < s.length(); j++)
		{
			sum += (s[j] - '0');
			int len = j - i + 1;
			int end = i - 1;
			int start = end - len + 1;
			if(m[{start, end}] == sum)
			{
				ans = max(ans, len * 2);
			}
			
			m[{i, j}] = sum;
		}
	}
	
	cout << ans;
}
