#include<bits/stdc++.h>

using namespace std;

int ans = 0;

bool checkPal(string s)
{
	int i = 0;
	int j = s.length() - 1;
	while(i <= j)
	{
		if(s[i] != s[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}

map<pair<string, pair<int, int> >, int> mp;

int find(string s, int i, int k)
{
	if(k == 0)
	{
		if(checkPal(s))
		{
			ans = 1;
			return 1;
		}
		return 0;
	}
	
	if(i == s.length())
	{
		return 0;
	}
	
	if(checkPal(s))
	{
		ans = 1;
		return 1;
	}
	
	if(mp.find({s, {i, k}}) != mp.end())
	{
		return mp[{s, {i, k}}];
	}
	
	int a = 0;
	
	a = find(s, i + 1, k);
	string ss = s.substr(0, i) + s.substr(i + 1);
	a = a || find(ss, i, k - 1);
	
	mp[{s, {i, k}}] = a;
	return a;
}

int main()
{
	string s;
	cin >> s;
	
	int k;
	cin >> k;
	
	cout << find(s, 0, k) << endl;
	cout << ans;
}
