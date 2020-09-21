#include<bits/stdc++.h>

using namespace std;

int ans = 0;

map<pair<string, int>, int> mp;

int find(set<string> st, string s, int i)
{
//	cout << s << endl;
	
	if(st.find(s) != st.end())
	{
		ans = 1;
		return 1;
	}
	
	if(i == s.length())
	{
		ans = 1;
		return 1;
	}
	
	if(mp.find({s, i}) != mp.end())
	{
		return mp[{s, i}];
	}
	
	int a = 0;
	
	for(int j = i; j < s.length(); j++)
	{
		string s1 = s.substr(i, j - i + 1);
//		cout << i << " s:" << s << " s1:" << s1 << " s2:";
		if(st.find(s1) != st.end())
		{
			string s2 = s.substr(j + 1, s.length() - s1.length());
//			cout << s2 << " ";
			a = a || find(st, s2, j + 1);
		}
//		cout << endl;
	}
	
	mp[{s, i}] = a;
	return a;
}

int main()
{
	set<string> st;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		st.insert(s);
	}
	
	string s;
	cin >> s;
	
	find(st, s, 0);
	cout << ans;
}
