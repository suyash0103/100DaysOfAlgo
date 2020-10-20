#include<bits/stdc++.h>

using namespace std;

int ans = 0;

map<pair<string, pair<int, int> >, int> mp;

int find(string s1, string s2, int i, int j)
{
//	cout << i << " " << j << " " << s1 << " " << s2 << endl;
	if(i >= s1.length() || j >= s2.length())
	{
		string ss = "";
		for(int k = 0; k < s1.length(); k++)
		{
			if(s1[k] >= 'A' && s1[k] <= 'Z')
			{
				ss.push_back(s1[k]);
			}
		}
		if(ss == s2)
		{
			ans = 1;
			return 1;
		}
		return 0;
	}
	
	if(mp.find({s1, {i, j}}) != mp.end())
	{
		return mp[{s1, {i, j}}];
	}
	
	int a = 0;

	if(s1[i] == s2[j])
	{
		a = a || find(s1, s2, i + 1, j + 1);
	}
	
	if(s1[i] == s2[j] + 32)
	{
		s1[i] = s1[i] - 32;
		a = a || find(s1, s2, i + 1, j + 1);
		s1[i] = s1[i] + 32;
	}
	
	int x = 0;
	
	string s = "";
	for(int k = 0; k < s1.length(); k++)
	{
		if(s1[k] >= 'A' && s1[k] <= 'Z')
		{
			s.push_back(s1[k]);
		}
		
		if(s1[k] >= 'a' && s1[k] <= 'z')
		{
			if(k < i)
			{
				x++;
			}
		}
	}
	
	int ii = i;
	
	if(x != 0 && s.length() > 0)
	{
		i -= x;
		a = a || find(s, s2, i, j);
	}
	
	a = a || find(s1, s2, ii + 1, j);
	
	mp[{s1, {i, j}}] = a;
	
	return a;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	
	cout << find(s1, s2, 0, 0) << endl;
	cout << ans;
}
