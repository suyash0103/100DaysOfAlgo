#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	
	int k;
	cin >> k;
	
	if(k == 1)
	{
		cout << s.length();
		return 1;
	}
	
	map<char, vector<int> > mp;
	for(int i = 0; i < s.length(); i++)
	{
		mp[s[i]].push_back(i);
	}
	
	map<char, vector<int> > :: iterator it;
	it = mp.begin();
	
	int ans = 0;
	
	while(it != mp.end())
	{
		vector<int> pl = it->second;
		for(int i = 0; i < pl.size(); i++)
		{
			for(int j = i + 1; j < pl.size(); j++)
			{
				int ele = j - i - 1;
				if(k == 2)
				{
					ans++;
				}
				else if(ele > 0 && k == 3)
				{
					ans += ele;
				}
			}
		}
		it++;
	}
	
	cout << ans;
}








