#include<bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> mp;

int find(string s, string t, int i, int j)
{
	if(j == t.length())
	{
		return 1;
	}
	
	if(i == s.length())
	{
		return 0;
	}
	
	if(mp.find({i, j}) != mp.end())
	{
		return mp[{i, j}];
	}
	
	if(s[i] == t[j])
	{
		mp[{i, j}] = find(s, t, i + 1, j + 1) + find(s, t, i + 1, j);
		return mp[{i, j}];
	}
	else
	{
		mp[{i, j}] = find(s, t, i + 1, j);
		return mp[{i, j}];
	}
}

int main()
{
	string s;
	string t;
	
	cin >> s >> t;
	
	cout << find(s, t, 0, 0);
}
